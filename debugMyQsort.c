
int main(int argc, char *argv[]) {

    int x;

    int data[] = {-100, -101, 7, 4, 9, 11, 11, 11, 10, 8, 0, 11, 10, 4, 1000, 1001};
    array_t array;
    array.array = data + 2;
    array.size = 12;

    myQsort(array.array, array.array, array.array + array.size - 1);

    for (x = 0; x < array.size; x++) {
        printf("%d\n", array.array[x]);
    }

    return 0;
}
