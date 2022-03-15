//
// Created by lizka on 15.03.2022.
//

#ifndef ASSESSMENTOFDIFFICULTIES2_SORT_H
#define ASSESSMENTOFDIFFICULTIES2_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../algorithms.h"


//обменная сортировка
void bubbleSort(int *a, size_t size);

//сортировка выбором
void selectionSort(int *a, const size_t size);

//сортировка вставками
void insertionSort(int *a, const size_t size);

//сортировка расческой
void combsort(int *a, const size_t size);

//сортировка Шелла
void shellSort(int *a, const size_t size);

//сортировка подсчетом
void countSort(int *a, const size_t size);

//цифровая сортировка
void radixSort(int *a, const size_t size);

#endif //ASSESSMENTOFDIFFICULTIES2_SORT_H
