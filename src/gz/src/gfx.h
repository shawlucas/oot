#ifndef __GFX_H_
#define __GFX_H_

#include <global.h>

void GfxTexldr_Init(GfxTexldr* this);
GfxTexture* GfxTexture_Load(const TexDesc* texdesc, GfxTexture* this);
void GfxTexldr_Destroy(GfxTexldr* this);
GfxTexture* GfxTexldr_Load(GfxTexldr* this, const TexDesc* texdesc, GfxTexture* texture);

#endif
