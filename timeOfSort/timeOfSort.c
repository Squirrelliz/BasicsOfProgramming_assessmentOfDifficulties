//
// Created by lizka on 15.03.2022.
//

#include "timeOfSort.h"

void
checkTime(void (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size, char *experimentName) {
    static size_t runCounter = 1;

    static int innerBuffer[10000000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);

    double time;
    TIME_TEST
    ({
         sortFunc(innerBuffer, size);
     }, time);

    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3f s.\n", time);


        char filename[256];
        sprintf(filename, ".//data//%s. csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf(" Wrong !\n");

        outputArray(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    SortFunc sorts[] = {
            //{bubbleSort,    " bubbleSort "},
            //{insertionSort, " insertionSort "},
            //{selectionSort, " selectionSort "},
            {combsort,      " combsort "},
            {shellSort,     " shellSort "},
            {radixSort,     " radixSort "}
    };

    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray, " random "},
            //{generateOrderedArray, " ordered "},
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 1000000; size <= 10000000; size += 1000000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {

                static char filename[128];
                sprintf(filename, "%s_%s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

void checkNComp(long long int (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size,
                char *experimentName) {
    static size_t runCounter = 1;

    static int innerBuffer[10000000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);

    long long nComp = sortFunc(innerBuffer, size);

    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Number of comparisons : %lld c.\n", nComp);


        char filename[256];
        sprintf(filename, ".//data//%s. csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComp);
        fclose(f);
    } else {
        printf(" Wrong !\n");

        outputArray(innerBuffer, size);

        exit(1);
    }
}

void nCompExperiment() {
    SortFuncNComp sorts[] = {
            //{getBubbleSortNComp,    " getBubbleSortNComp "},
            //{getInsertionSortNComp, " getInsertionSortNComp "},
            //{getSelectionSortNComp, " getSelectionSortNComp "},
            {getCombsortNComp,      " getCombsortNComp "},
            {getShellSortNComp,     " getShellSortNComp "},
            {getRadixSortNComp,     " getRadixSortNComp "}
    };

    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray, " random "},
            //{generateOrderedArray, " ordered "},
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 1000000; size <= 10000000; size += 1000000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {

                static char filename[128];
                sprintf(filename, "%s_%s_nComps ",
                        sorts[i].name, generatingFuncs[j].name);
                checkNComp(sorts[i].sort,
                           generatingFuncs[j].generate,
                           size, filename);
            }
        }
        printf("\n");
    }
}
