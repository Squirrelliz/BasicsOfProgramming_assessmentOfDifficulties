//
// Created by lizka on 15.03.2022.
//

#include "sort.h"

//обменная сортировка
void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

//сортировка выбором
void selectionSort(int *a, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

//сортировка вставками
void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

//сортировка расческой
void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

//сортировка Шелла
void shellSort(int *a, const size_t size) {
    for (int step = size / 2; step > 0; step /= 2) {
        for (size_t i = step; i < size; i++) {
            int t = a[i];
            int j = i;
            while (j - step >= 0 && a[j - step] > t) {
                a[j] = a[j - step];
                j -= step;
            }
            a[j] = t;
        }
    }
}

//цифровая сортировка
void radixSort(int *a, const size_t size) {
    int *buffer = (int *) calloc(size, sizeof(int));
    int maxByteValue = 0b11111111;
    int step = 8;
    int nBytes = sizeof(int);

    for (int byte = 0; byte < nBytes; byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < size; i++) {
            int currentByte;
            if (byte + 1 == nBytes)
                currentByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & maxByteValue;
            else
                currentByte = (a[i] >> (byte * step)) & maxByteValue;

            values[currentByte]++;
        }

        getPrefixSum(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size; i++) {
            int currentByte;
            if (byte + 1 == nBytes)
                currentByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & maxByteValue;
            else
                currentByte = (a[i] >> (byte * step)) & maxByteValue;

            buffer[values[currentByte]++] = a[i];
        }
        memcpy(a, buffer, nBytes * size);
    }

    free(buffer);
}

//обменная сортировка с подсчетом операций сравнения
long long getBubbleSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < size - 1; i++)
        for (size_t j = size - 1; ++nComps && j > i; j--)
            if (++nComps && a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
    return nComps;
}

//сортировка выбором с подсчетом операций сравнения
long long getSelectionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

//сортировка вставками с подсчетом операций сравнения
long long getInsertionSortNComp(int *a, const size_t size) {
    long long nComps = 0;
    for (size_t i = 1; ++nComps && i < size; i++) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}

//сортировка расческой с подсчетом операций сравнения
long long getCombsortNComp(int *a, const size_t size) {
    long long nComps = 0;
    size_t step = size;
    int swapped = 1;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }

    return nComps;
}

//сортировка Шелла с подсчетом операций сравнения
long long getShellSortNComp(int *a, const size_t size) {
    long long nComps = 0;
    for (int step = size / 2; ++nComps && step > 0; step /= 2) {
        for (size_t i = step; ++nComps && i < size; i++) {
            int t = a[i];
            int j = i;
            while (++nComps && j - step >= 0 && a[j - step] > t) {
                a[j] = a[j - step];
                j -= step;
            }
            a[j] = t;
        }
    }

    return nComps;
}

//цифровая сортировка с подсчетом операций сравнения
long long getRadixSortNComp(int *a, const size_t size) {
    long long nComps = 0;
    int *buffer = (int *) calloc(size, sizeof(int));
    int maxByteValue = 0b11111111;
    int step = 8;
    int nBytes = sizeof(int);

    for (int byte = 0; ++nComps && byte < nBytes; byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; ++nComps && i < size; i++) {
            int currentByte;
            if (++nComps && byte + 1 == nBytes)
                currentByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & maxByteValue;
            else
                currentByte = (a[i] >> (byte * step)) & maxByteValue;

            values[currentByte]++;
        }

        getPrefixSum(values, UCHAR_MAX + 1);

        for (size_t i = 0; ++nComps && i < size; i++) {
            int currentByte;
            if (++nComps && byte + 1 == nBytes)
                currentByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & maxByteValue;
            else
                currentByte = (a[i] >> (byte * step)) & maxByteValue;

            buffer[values[currentByte]++] = a[i];
        }
        memcpy(a, buffer, nBytes * size);
    }

    free(buffer);

    return nComps;
}
