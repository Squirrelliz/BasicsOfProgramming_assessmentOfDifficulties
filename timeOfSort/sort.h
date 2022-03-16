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

//цифровая сортировка
void radixSort(int *a, const size_t size);

//обменная сортировка с подсчетом операций сравнения
long long getBubbleSortNComp(int *a, size_t size);

//сортировка выбором с подсчетом операций сравнения
long long getSelectionSortNComp(int *a, size_t n);

//сортировка вставками с подсчетом операций сравнения
long long getInsertionSortNComp(int *a, const size_t size);

//сортировка расческой с подсчетом операций сравнения
long long getCombsortNComp(int *a, const size_t size);

//сортировка Шелла с подсчетом операций сравнения
long long getShellSortNComp(int *a, const size_t size);

//цифровая сортировка с подсчетом операций сравнения
long long getRadixSortNComp(int *a, const size_t size);

#endif //ASSESSMENTOFDIFFICULTIES2_SORT_H
