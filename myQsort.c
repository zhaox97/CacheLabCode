#include "cacheTestTools.h"
#include "myQsort.h"

/*
 * This code is a combination of the Java implementation and
 * https://code.woboq.org/userspace/glibc/stdlib/qsort.c.html
 */

void vecswap(int *a, int *b, int size) {
    int* end = a + size;
    while (a < end) {
        int temp = *a;
        *a = *b;
        *b = temp;
        ++a;
        ++b;
    }
}

void myQsort(int *array, int *begin, int *end) {

   /* This is just helpful for debugging in CLion */
   // int (*dArray)[12] = array;

    register int *left = begin;
    register int *right = end;

    register int pivot_loc = (int)(end - begin) / 2;
    register int val1 = *begin;
    register int val2 = begin[pivot_loc];
    register int val3 = *end;

    if (right <= left) {
        return;
    }


    if (pivot_loc > 2) {
        /* Pick the median of these three if there are at least 4 element in the array
           credit: https://stackoverflow.com/questions/7559608/median-of-three-values-strategy
        */

        /* pivot is at the beginning.  Do nothing. */
        if ((val1 > val2) ^ (val1 > val3)) {}
            /* pivot is at the end.  Swap with the beginning */
        else if ((val2 < val1) ^ (val2 < val3)) {
            val1 = *begin;
            *begin = *end;
            *end = val1;
        } else {
            /* pivot is the midpoint.  Swap with the beginning */
            val1 = *begin;
            *begin = begin[pivot_loc];
            begin[pivot_loc] = val1;
        }
    }

    val1 = *begin;
    register int *mid_left = left;
    register int *mid_right = right;

    /* partition */
    while (1) {
        while (*left <= val1 && left <= right) {
            /* push any copies of the pivot to the left */
            if (*left == val1) {
                val2 = *left;
                *left = *mid_left;
                *mid_left = val2;
                ++mid_left;
            }
            ++left;
        }

        while (*right >= val1 && right >=left) {
            if (*right == val1) {
                val2 = *right;
                *right = *mid_right;
                *mid_right = val2;
                --mid_right;
            }
            --right;
        }

     if (left > right) {
         break;
     }
            val2 = *left;
            *left = *right;
            *right = val2;
    } /* end outer while */

    /* Swap partition elements back to the middle. */
    register int shorter = mid_left - begin < left - mid_left ? (int)(mid_left - begin) : (int)(left - mid_left);
    vecswap(left-shorter, begin, shorter);

    shorter = mid_right - right < end-mid_right ? (int)(mid_right - right) : (int)(end - mid_right);
    vecswap(left, end - shorter + 1, shorter);

    /* (Helpful for debugging)
      int* end1 = begin + (int)(left-mid_left)-1;
      int* begin2 = right + 1 + (int)(end - mid_right);
    */
    myQsort(array, begin, begin + (int)(left-mid_left)-1);
    myQsort(array, right + 1 + (int)(end - mid_right), end);

} /* end myQsort */

