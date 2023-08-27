#include "global.h"

s32 Overlay_Load(uintptr_t vromStart, uintptr_t vromEnd, void* vramStart, void* vramEnd, void* allocatedRamAddr) {
    s32 pad[3];
    uintptr_t end;
    OverlayRelocationSection* ovlRelocs;
    u32 relocSectionOffset;
    size_t size;

    size = vromEnd - vromStart;
    end = (uintptr_t)allocatedRamAddr + size;

    if (gOverlayLogSeverity >= 3) {
        // "Start loading dynamic link function"
        osSyncPrintf("\nStart loading dynamic link function\n");
    }

    if (gOverlayLogSeverity >= 3) {
        // "DMA transfer of TEXT, DATA, RODATA + rel (%08X-%08X)"
        osSyncPrintf("DMA transfer of TEXT, DATA, RODATA + rel (%08X-%08X)\n", allocatedRamAddr, end);
    }

    // DMA the overlay, wait until transfer completes
    DmaMgr_RequestSync(allocatedRamAddr, vromStart, size);

    // The overlay file is expected to contain a 32-bit offset from the end of the file to the start of the
    // relocation section.
    relocSectionOffset = ((s32*)end)[-1];
    ovlRelocs = (OverlayRelocationSection*)(end - relocSectionOffset);

    if (gOverlayLogSeverity >= 3) {
        osSyncPrintf("TEXT(%08X), DATA(%08X), RODATA(%08X), BSS(%08X)\n", ovlRelocs->textSize, ovlRelocs->dataSize,
                     ovlRelocs->rodataSize, ovlRelocs->bssSize);
    }

    if (gOverlayLogSeverity >= 3) {
        osSyncPrintf("Relocate\n"); // "Relocate"
    }

    // Relocate pointers in overlay code and data
    Overlay_Relocate(allocatedRamAddr, ovlRelocs, vramStart);

    // Clear bss if present, bss is located immediately following the relocations
    if (ovlRelocs->bssSize != 0) {
        if (gOverlayLogSeverity >= 3) {
            // "Clear BSS area (% 08x-% 08x)"
            osSyncPrintf("Clear BSS area(%08X-%08X)\n", end, end + ovlRelocs->bssSize);
        }
        bzero((void*)end, ovlRelocs->bssSize);
    }

    size = (uintptr_t)&ovlRelocs->relocations[ovlRelocs->nRelocations] - (uintptr_t)ovlRelocs;

    if (gOverlayLogSeverity >= 3) {
        // "Clear REL area (%08X-%08X)"
        osSyncPrintf("Clear REL area(%08X-%08X)\n", ovlRelocs, (uintptr_t)ovlRelocs + size);
    }

    // Clear relocations, this space remains allocated and goes unused
    bzero(ovlRelocs, size);

    // Manually flush caches
    size = (uintptr_t)vramEnd - (uintptr_t)vramStart;
    osWritebackDCache(allocatedRamAddr, size);
    osInvalICache(allocatedRamAddr, size);

    if (gOverlayLogSeverity >= 3) {
        // "Finish loading dynamic link function"
        osSyncPrintf("Finish loading dynamic link function\n\n");
    }
    return size;
}
