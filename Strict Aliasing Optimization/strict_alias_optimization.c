#include <stdint.h>
#include <stdio.h>

typedef union U32_t {
    uint32_t u32;
    uint16_t u16[2];
} U32;

void swapWords (uint32_t *arg)
{
    U32 *combined = (U32*)arg;
    /*
    U32 result = {.u16[0] = combined->u16[1], .u16[1] = combined->u16[0] };
    *arg = *(uint32_t *)&result;
    */
    uint32_t start = combined->u32;
    uint32_t lo = start >> 16;
    uint32_t hi = start << 16;
    uint32_t final = lo | hi;
    combined->u32 = final;
}

int main ()
{
    uint32_t value = 0x00001111;
    swapWords(&value);
    printf("%08X\n", value);
    return 0;
}
