#include <stdlib.h>
#include "cacheTestTools.h"
#include "myQsort.h"

int main() {

    for (int i = 0; i < 1000000; ++i) {

        int size = rand() % 1024 + 1024;
        int max = rand() % 3*size + 1;

        array_t array;
        makeAndLoadRandom(size, max, &array);
        int* orig = malloc(array.size * sizeof(int));
        memcpy(orig, array.array, array.size*sizeof(int));

        myQsort(array.array, array.array, array.array + array.size - 1);
        if (!verify(array)) {
            for (int x = 0; x < array.size; x++) {
                printf("%d\n", orig[x]);
            }
            break;
        } else {
            if (i % 1000 == 1) {
                printf(".");
                fflush(stdout);
            }
        }
        free(array.array);
        free(orig);
    }
}
