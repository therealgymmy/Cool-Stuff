// refer to my blog post:
// http://beyondsora.wordpress.com/2012/10/16/restrict-keyword/

#include <stdint.h>
#include <stdlib.h>

#ifdef OPT
 #define RESTRICT restrict
#else
 #define RESTRICT
#endif

typedef struct {
    uint32_t meal_plan;
    uint32_t tuition;
    uint32_t bus_pass;
    uint32_t activity_fee;
} StudentFee;

void resetAllFee (uint32_t n, StudentFee *RESTRICT students, StudentFee *RESTRICT standardOfSemester);
