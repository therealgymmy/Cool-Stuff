// refer to my blog post:
// http://beyondsora.wordpress.com/2012/10/17/restrict-keyword/

#include "test.h"

void foo (Buffer *buffer, uint32_t *values) {
    uint32_t length = sizeof(Buffer) / sizeof(uint32_t);
    for (int i = 0; i < length; ++i)
        values[i] += (uint32_t)buffer->num[0];
}
