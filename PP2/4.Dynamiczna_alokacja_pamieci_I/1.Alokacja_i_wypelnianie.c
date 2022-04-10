#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int main()
{
    int* arr = (int*)malloc(100u * sizeof(int));

    if (arr == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }

    for (int i = 0; i < 100; ++i)
    {
        *(arr + i) = i;
    }
    
    for (int* s = arr; s < arr + 100; ++s)
    {
        printf("%d ", *s);
    }
    
    free(arr);
    return 0;
}
