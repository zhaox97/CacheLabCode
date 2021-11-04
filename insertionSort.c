void insertionSort(int *begin, int *end) {

    int* c = begin + 1;
    while (c <= end) {
        int key = *c;
        int *ptr = c -1;
        while (ptr >= begin && key < *ptr) {
            *(ptr+1) = *ptr;
            --ptr;
        }
        *(ptr+1) = key;
        ++c;
    }
}