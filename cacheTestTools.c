#include "cacheTestTools.h"
#include <time.h>
#include <stdlib.h>

void makeAndLoadRandom(int size, int max, array_t* array) {
    srand(time(NULL));
    array->array = malloc(size * sizeof(int));
    array->size = size;
    for (int i = 0; i < size; ++i) {
        array->array[i] = rand() % max;
    }
}

int makeAndLoadArray(FILE* input, array_t* array)
{
  register int place = 0;
  int size;
  int temp;
  register int ret = fscanf(input, "%d", &size);
  if (ret < 1) {
    return 0;
  }

  array->array = malloc(size * sizeof(int));
  array->size = size;

  for (place = 0; place < size; place++) {
    if (fscanf(input, "%d", &temp) < 1) {
      return 0;
    }
    array->array[place] = temp;
  }
  return 1;
}

int intcomp(const void *p1, const void *p2) 
{
  return *((int*)p1) - *((int*)p2);
}


array_t initialize(int argc, char* argv[]) 
{

  FILE* input = stdin;
  array_t array;

  if (argc > 1) {
      /* Load with random numbers */
      if (strncmp(argv[1], "-r", 2) == 0) {
          int max = 25;
          if (argc > 2) {
              sscanf("%d", argv[2], &max);
          }

        makeAndLoadRandom(max, max/2,&array);
        return array;
      }

    input = fopen(argv[1], "r+");
    if (input == NULL) {
      fprintf(stderr, "Couldn't open %s\n", argv[1]);
      exit(1);
    }
  }

  if (makeAndLoadArray(input, &array) < 1) {
    fprintf(stderr, "Error loading data\n");
    exit(1);
  }

  return array;
}

int verify(array_t array) {
    for (int i = 1; i < array.size; ++i) {
        if (array.array[i] < array.array[i-1]) {
            printf("\nProblem!!!!\n");
            return 0;
        }
    }
    return 1;
}