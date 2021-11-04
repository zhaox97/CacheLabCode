#include <stdlib.h>
#include "cacheTestTools.h"

/* Run the qsort version that comes with the C library */
int main(int argc, char *argv[]) {

    int x;
    array_t array = initialize(argc, argv);

    qsort(array.array, array.size, sizeof(int), intcomp);

    for (x = 0; x < array.size; x++) {
        printf("%d\n", array.array[x]);
    }

    return 0;
}
