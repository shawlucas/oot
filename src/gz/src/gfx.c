#include <ultra64.h>
#include <global.h>

void GfxTexldr_Init(GfxTexldr* this) {
    this->vaddr = -1;
    this->data = NULL;
}

#define G_SIZ_BITS(siz)               (4<<gI_(siz))

GfxTexture* GfxTexldr_Load(GfxTexldr* this, const TexDesc* texdesc, GfxTexture* texture) {
    size_t textureSize;
    void* textureData;
    void* fileStart;
    GfxTexture* newTexture = NULL;
    if (!texture) {
        newTexture = malloc(sizeof(*newTexture));
        if (!newTexture)
            return newTexture;
        texture = newTexture;
    }

    texture->imFmt = texdesc->imFmt;
    texture->imSiz = texdesc->imSiz;
    texture->tileWidth = texdesc->tileWidth;
    texture->tileHeight = texdesc->tileHeight;
    texture->tileX = texdesc->tilesX;
    texture->tilesY = texdesc->tilesY;
    texture->tileSize = (texture->tileWidth * texture->tileHeight * G_SIZ_BITS(texture->imSiz) + 63) / 64 * 8;
    textureSize = texture->tileSize * texture->tileX * texture->tilesY;

    textureData = NULL;
    fileStart = NULL;
    if (texdesc->fileVaddr != -1) {
        if (this->vaddr != texdesc->fileVaddr) {
            if (this->data)
                free(this->data);
            this->data = malloc(texdesc->fileVsize);
            if (!this->data) {
                this->vaddr = -1;
                if (newTexture) 
                    free(newTexture);
                return NULL;
            }
            this->vaddr = texdesc->fileVaddr;
            DmaMgr_SendRequest0(this->data, this->vaddr, texdesc->fileVsize); // WARNING THIS MIGHT CRASH !!!!
        }

        if (texdesc->fileVsize == textureSize) {
            textureData = this->data;
            this->vaddr = -1;
            this->data = NULL;
        } else 
            fileStart = this->data;
    }

    if (!textureData) {
        textureData = malloc(textureSize);
        if (!textureData) {
            if (newTexture)
                free(newTexture);
            return NULL;
        }

        memcpy(textureData, (char *)fileStart + texdesc->address, textureSize);
    }
    texture->data = textureData;
    return texture;
}

void GfxTexldr_Destroy(GfxTexldr* this) {
    if (this->data)
        free(this->data);
}

GfxTexture* GfxTexture_Load(const TexDesc* texdesc, GfxTexture* this) {
    GfxTexldr texldr;
    GfxTexldr_Init(&texldr);
    this = GfxTexldr_Load(&texldr, texdesc, this);
    GfxTexldr_Destroy(&texldr);
    return this;
}