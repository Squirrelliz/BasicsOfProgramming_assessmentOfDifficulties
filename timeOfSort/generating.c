//
// Created by lizka on 15.03.2022.
//

#include "generating.h"

//генерирует массив случайных целых чисел
void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() - RAND_MAX / 2;
    }
}

//генерирует массив неотрицательных чисел в порядке возрастания
void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
}

//генерирует массив неотрицательных чисел в порядке убывания
void generateOrderedBackwards(int *a, size_t n) {
    for (int i = n - 1; i >= 0; --i) {
        a[n-i-1] = i;
    }
}
