
CFLAGS := -Wall -O0

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

runMyQsort:  cacheTestTools.o myQsort.o runMyQsort.o
	$(CC) $^ -o $@ 

runInsertionSort: cacheTestTools.o insertionSort.o runInsertionSort.o
	$(CC) $^ -o $@

clean::
	rm *.o
