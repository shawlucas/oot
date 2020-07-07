#include <global.h>

u32 D_8012DBA0 = (u32)&D_80155F50;
u32 D_8012DBA4 = (u32)&D_80157580;

u32 SysUcode_GetUCodeBoot() {
    return &build_asm_rspbootTextStart;
}

u32 SysUcode_GetUCodeBootSize() {
    return (u32)&build_asm_rspbootTextEnd - (u32)&build_asm_rspbootTextStart;
}

u32 SysUcode_GetUCode() {
    return D_8012DBA0;
}

u32 SysUcode_GetUCodeData() {
    return D_8012DBA4;
}
