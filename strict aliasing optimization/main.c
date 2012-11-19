// refer to my blog post:
// http://beyondsora.wordpress.com/2012/10/17/restrict-keyword/

#include "test.h"

int main ()
{
    Buffer buffer = { .num = {0} };
    buffer.num[0] = 0x0010;
    foo(&buffer, (uint32_t*)&buffer);

    for (int i = 0; i < 32; ++i) {
        printf("%04X\n", buffer.num[i]);
    }

    return 0;
}
