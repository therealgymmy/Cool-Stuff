// refer to my blog post:
// http://beyondsora.wordpress.com/2012/10/17/restrict-keyword/

#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint16_t num[32];
} Buffer;

void foo (Buffer *buffer, uint32_t *values);
