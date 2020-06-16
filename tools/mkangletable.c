#include <stdio.h>
#include <math.h>

int main()
{
    int angle;
    printf("static s16 sintable[0x400] = {\n");
    for (int i = 0; i < 0x400; i++)
    {
        angle = (int)(sin(i * (M_PI/2) / 0x3FF) * 32767);
        if (angle < 0) {
            angle = 0;
        }
        if (angle > 32767) {
            angle = 32767;
        }
        printf("\t0x%04x,\n", angle);
    }

    printf("};\n");
    return 0;
}