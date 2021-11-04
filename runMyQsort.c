#include "cacheTestTools.h"
#include "myQsort.h"

int main(int argc, char *argv[]) {

    int x;
    array_t array = initialize(argc, argv);

    myQsort(array.array, array.array, array.array + array.size - 1);

    for (x = 0; x < array.size; x++) {
        printf("%d\n", array.array[x]);
    }

    return 0;
}
