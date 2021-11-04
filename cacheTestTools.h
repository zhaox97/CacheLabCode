#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int* array;
  int size;
} array_t;


int makeAndLoadArray(FILE* input, array_t* array);
void makeAndLoadRandom(int size, int max, array_t* array);

int intcomp(const void *p1, const void *p2);

array_t initialize(int argc, char* argv[]);

int verify(array_t array);