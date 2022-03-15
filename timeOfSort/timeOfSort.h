//
// Created by lizka on 15.03.2022.
//

#ifndef ASSESSMENTOFDIFFICULTIES2_TIMEOFSORT_H
#define ASSESSMENTOFDIFFICULTIES2_TIMEOFSORT_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "sort.h"
#include "generating.h"
#include "../algorithms.h"

#define TIME_TEST(testCode, time) {\
 clock_t start_time = clock () ;\
 testCode\
 clock_t end_time = clock () ;\
 clock_t sort_time = end_time - start_time;\
 time = ( double )sort_time/CLOCKS_PER_SEC;\
 }

#define ARRAY_SIZE(a)sizeof(a)/sizeof(a[0])


typedef struct SortFunc {
    void (*sort )(int *a, size_t n);

    char name[64];
} SortFunc;

typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n);

    char name[64];
} GeneratingFunc;

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName);

void timeExperiment();


#endif //ASSESSMENTOFDIFFICULTIES2_TIMEOFSORT_H
