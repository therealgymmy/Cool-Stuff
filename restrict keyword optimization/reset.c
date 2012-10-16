// refer to my blog post:
// http://beyondsora.wordpress.com/2012/10/16/restrict-keyword/

#include "reset.h"

void resetAllFee (uint32_t n, StudentFee *RESTRICT students, StudentFee *RESTRICT standardOfSemester)
{
    for (uint32_t i = 0; i < n; ++i) {
        students[i].meal_plan = standardOfSemester->meal_plan;
        students[i].tuition = standardOfSemester->tuition;
        students[i].bus_pass = standardOfSemester->bus_pass;
        students[i].activity_fee = standardOfSemester->activity_fee;
    }
}
