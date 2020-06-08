#include <ultra64.h>
#include <global.h>

void func_80815CE0(Gfx** dlist)
{
    s32 pad[2];
    GfxPrint printer[2];
    Gfx* newDList;
    
    GfxPrint_Ctor(printer);
    GfxPrint_Open(printer, *dlist);
    GfxPrint_SetPos(printer, 4, 2);
    GfxPrint_SetColor(printer, 0xFF, 0x3C, 0x00, 0xFF);
    GfxPrint_Printf(printer, "%s", "\x8Cﾙﾋﾟｰ"); // "Rupee"
    GfxPrint_SetPos(printer, 0xF, 2);
    GfxPrint_Printf(printer, "%s", "\x8Cﾊｰﾄ"); // "Heart"
    GfxPrint_SetPos(printer, 0x1A, 3);
    GfxPrint_Printf(printer, "%s", "/4");
    GfxPrint_SetPos(printer, 4, 5);
    GfxPrint_Printf(printer, "%s", "\x8Cｱｲﾃﾑ"); // "Item"
    GfxPrint_SetPos(printer, 4, 0xD);
    GfxPrint_Printf(printer, "%s", "KEY");
    GfxPrint_SetPos(printer, 4, 0xF);
    GfxPrint_Printf(printer, "%s", "\x8Dｿｳﾋﾞ"); // "Equipment"
    GfxPrint_SetPos(printer, 0x17, 0xE);
    GfxPrint_Printf(printer, "%s", "\x8Cｹﾝ"); // "Sword"
    GfxPrint_SetPos(printer, 0x17, 0xF);
    GfxPrint_Printf(printer, "%s", "\x8Cﾀﾃ"); // "Shield"
    GfxPrint_SetPos(printer, 4, 0x11);
    GfxPrint_Printf(printer, "%s", "MAP");
    GfxPrint_SetPos(printer, 4, 0x13);
    GfxPrint_Printf(printer, "%s", "\x8Dﾌｳｲﾝ"); // "Seal"
    GfxPrint_SetPos(printer, 0x14, 0x13);
    GfxPrint_Printf(printer, "%s", "\x8Dｾｲﾚｲｾｷ"); // "Spiritual Stone"
    GfxPrint_SetPos(printer, 4, 0x15);
    GfxPrint_Printf(printer, "%s", "\x8Cｵｶﾘﾅ"); // "Ocarina"
    GfxPrint_SetPos(printer, 4, 0x18);
    GfxPrint_Printf(printer, "%s", "\x8Cｺﾚｸﾄ"); // "Collectables"
    GfxPrint_SetPos(printer, 0xE, 0x18);
    GfxPrint_Printf(printer, "%s", "\x8Cｷﾝｽﾀ"); // "Gold Skulltula"
    GfxPrint_SetPos(printer, 0x17, 0x18);
    GfxPrint_Printf(printer, "%s", "\x8Cｶｹﾗ"); // "Piece of Heart"
    GfxPrint_SetPos(printer, 0x1C, 0x18);
    GfxPrint_Printf(printer, "%s", "/4");
    newDList = GfxPrint_Close(printer);
    *dlist = newDList;
    GfxPrint_Dtor(printer);
}

#if 0
void func_80815FD4(GlobalContext* globalCtx, u32 arg1, s32 arg2, s32 arg3)
{
    GraphicsContext* gfxCtx;
    Gfx* dispRefs[4];

    gfxCtx = globalCtx->state.gfxCtx;

    Graph_OpenDisps(dispRefs, globalCtx->state.gfxCtx, "../z_kaleido_debug.c", 208);
    gDPSetTextureImage(gfxCtx->polyOpa.p++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_02003040[arg1]);
    gDPSetTile(gfxCtx->polyOpa.p++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_CLAMP, 0, 0, G_TX_WRAP | G_TX_CLAMP, 0, 0);
    gDPLoadSync(gfxCtx->polyOpa.p++);
    gDPPipeSync(gfxCtx->polyOpa.p++);
    gDPLoadBlock(gfxCtx->polyOpa.p++, G_TX_LOADTILE, 0, 0, 63, (1<<11));
    gDPSetTile(gfxCtx->polyOpa.p++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_CLAMP, 0, 0, G_TX_WRAP | G_TX_CLAMP, 0, 0);
    gDPSetTileSize(gfxCtx->polyOpa.p++, G_TX_RENDERTILE, 0, 0, (7<<2), (15<<2));
   // gDPLoadTextureBlock(gfxCtx->polyOpa.p++, (u32) &D_02003040[arg1], G_IM_FMT_I, G_IM_SIZ_8b, 8, 16, 0, G_TX_WRAP | G_TX_CLAMP, G_TX_WRAP | G_TX_CLAMP, 0, 0, 0, 0);
    gSPTextureRectangle(gfxCtx->polyOpa.p++, arg2 * 4, arg3 * 4, (arg2 + 8) * 4, (arg3 + 0x10) * 4, G_TX_RENDERTILE, 0, 0, (32<<5), (32<<5));
    //temp_v0_8->words.w1 = (u32) ((((arg2 * 4) & 0xFFF) << 0xC) | ((arg3 * 4) & 0xFFF));
    //temp_v0_8->words.w0 = (u32) ((((((arg2 + 8) * 4) & 0xFFF) << 0xC) | 0xE4000000) | (((arg3 + 0x10) * 4) & 0xFFF));
    Graph_CloseDisps(dispRefs, globalCtx->state.gfxCtx, "../z_kaleido_debug.c", 220);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80815FD4.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808161AC.s")
