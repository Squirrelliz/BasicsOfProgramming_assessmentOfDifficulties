//
// Created by lizka on 15.03.2022.
//

#include "algorithms.h"
#include <assert.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

/*возвращает индекс первого элемента со значением x
в массиве a размера n, если элемент найден, иначе – (-1)*/
size_t leftLinearSearch(const int *a, const size_t n, const int x) {
    for (size_t i = 0; i < n; i++) {
        if (a[i] == x)
            return i;
    }
    return n;
}

//добавляет элемент value в конец массива a размером n
void append(int *a, size_t *n, const int value) {
    a[*n] = value;
    (*n)++;
}

/*удаляет элемент по индексу position из массива a размера n, не сохраняя порядок элементов.
 Уменьшает количество элементов n на единицу.*/
void deleteByPosUnsaveOrder(int *a, size_t *n, const size_t position) {
    a[position] = a[*n - 1];
    (*n)--;
}

//вывод массива по адресу a размера n
void outputArray(const int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d, ", a[i]);
}

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int binarySearch(const int *a, const int n, const int value) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (a[middle] > value)
            right = middle - 1;
        else if (a[middle] < value)
            left = middle + 1;
        else
            return middle;
    }
    return n;
}

int compareInts(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

/*вставляет значение value в позицию position массива a размера n.
Увеличивает количество элементов n на единицу.*/

void insertValue(int *const a, size_t *const n, const size_t pos, const int value) {
    assert(pos <= *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;

        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}


bool isOrdered(const int *a, size_t n) {
    int i = 1;
    while (i < n && a[i - 1] <= a[i])
        i++;
    return i == n;
}


int isMore(const int x, const int y) {
    return x > y;
}

int binarySearchCriteria(const int *a, const int n, int conditionalDigit, int (fCriteria)(int, int)) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (fCriteria(a[middle], conditionalDigit))
            right = middle;
        else
            left = middle;
    }
    return left;
}

void deleteByPosSaveOrder(int *a, int *n, const size_t position) {
    for (size_t i = position; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

int binarySearchEqualOrMore(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}


long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return min;
}

bool isUnique(long long int *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                return 0;
        }
    }
    return 1;
}

int max(int a, int b) {
    int m = a > b ? a : b;
    return m;
}

int min2(int a, int b) {
    int m = a < b ? a : b;
    return m;
}

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; ++i) {
        distance += a[i] * a[i];
    }

    return sqrt(distance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

}

int countNUnique(long long int *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int nUniqueElements = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1])
            nUniqueElements++;
    }
    return nUniqueElements;
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == value)
            count++;
    }
    return count;
}

bool isEqualOrMore(const int *a, const size_t n, const int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= x)
            return true;
    }
    return false;
}

bool isEqualOrLess(const int *a, const size_t n, const int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= x)
            return true;
    }
    return false;
}

int cmp_char(const void *pa, const void *pb) {
    char arg1 = *(const char *) pa;
    char arg2 = *(const char *) pb;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

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

void getPrefixSum(int *a, size_t size) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; i < size; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}
