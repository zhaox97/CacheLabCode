#include <stdlib.h>
#include "cacheTestTools.h"

void runClibQsort(int* begin, int* end) {
    qsort(begin, (int)(end-begin), sizeof(int), intcomp);
}


/* Run the qsort version that comes with the C library */
int main(int argc, char *argv[]) {

   runSort(argc, argv, runClibQsort);

    return 0;
}
