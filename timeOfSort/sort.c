//
// Created by lizka on 15.03.2022.
//

#include "sort.h"

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void getMinMax(const int *a, size_t size, int *min, int *max) {
    *min = a[0];
    *max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < *min)
            *min = a[i];
        else if (a[i] > *max)
            *max = a[i];
    }
}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

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

void countSort(int *a, const size_t size) {
    int min, max;
    getMinMax(a, size, &min, &max);
    int k = max - min + 1;

    int *b = (int *) calloc(k, sizeof(int));
    for (int i = 0; i < size; i++)

        b[a[i] - min]++;

    int ind = 0;
    for (int i = 0; i < k; i++) {
        int x = b[i];
        for (int j = 0; j < x; j++)
            a[ind++] = min + i;
    }

    free(b);
}

void getPrefixSum(int *a, size_t size) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; i < size; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}

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
