#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int main()
{
    float* num = (float*)malloc(sizeof(float));
    if (num == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    *num = M_PI;

    printf("%f, %p", *num, (void*)num);

    free(num);
    return 0;
}
