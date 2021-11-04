void insertionSort(int *begin, int *end) {

    register int* c = begin + 1;
    while (c <= end) {
        register int key = *c;
        register int *ptr = c -1;
        while (ptr >= begin && key < *ptr) {
            *(ptr+1) = *ptr;
            --ptr;
        }
        *(ptr+1) = key;
        ++c;
    }
}