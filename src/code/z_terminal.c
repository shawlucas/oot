#include <ultra64.h>
#include <global.h>

void Terminal_SetupTerminal(GfxPrint* printer)
{
    GfxPrint_SetPos(printer, 1, 1);
    GfxPrint_Printf(printer, "%s", "Hello, World!");
}