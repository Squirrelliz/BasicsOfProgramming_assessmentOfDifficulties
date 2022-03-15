#include <stdio.h>
#include "timeOfSort/sort.h"

int main () {
    //timeExperiment ();
    int a[10] ={89,391,4,2,194,20};
    radixSort(a, 6);
    outputArray_(a,6);
    return 0;
}
