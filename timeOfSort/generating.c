//
// Created by lizka on 15.03.2022.
//

#include "generating.h"

void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() - RAND_MAX / 2;
    }
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
}

void generateOrderedBackwards(int *a, size_t n) {
    for (int i = n - 1; i >= 0; --i) {
        a[i] = i;
    }
}
