// refer to my blog post:
// http://beyondsora.wordpress.com/2012/10/16/restrict-keyword/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "reset.h"

int main ()
{
    uint32_t number = 10000000;
    StudentFee *students = malloc(number * sizeof(StudentFee));
    StudentFee *standard = malloc(sizeof(StudentFee));
    standard->meal_plan = 1000;
    standard->tuition = 5000;
    standard->bus_pass = 100;
    standard->activity_fee = 500;

    int start, end;
    start = clock();
    for (int i = 0; i < 10000; ++i) {
        resetAllFee(number, students, standard);
    }
    end = clock();

    printf("%d\n", (end - start) / 1000);

    return 0;
}
