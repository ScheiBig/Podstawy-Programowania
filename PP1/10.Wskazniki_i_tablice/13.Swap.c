#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int swap(int*, int*);

int main()
{
    int num_1;
    int num_2;
    print_ln("Enter two numbers:");
    if (scanf("%d %d", &num_1, &num_2) != 2)
    {
        __m_exit(eINPUT_invalid);
    }
    swap(&num_1, &num_2);
    printf_ln("%d %d", num_1, num_2);
    return 0;
}

int swap(int* _1, int* _2)
{
    if (_1 == null || _2 == null)
    {
        return 1;
    }
    int temp = *(_1);
    *(_1) = *(_2);
    *(_2) = temp;
    return 0;
}