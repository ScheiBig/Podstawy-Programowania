#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
#include "vector_utils.h"

int create_histogram(const float* vec, int size, int* out, int out_size);

int main()
{
    float nums[100];
    int num_cnt;
    print_ln("Enter an array:");
    switch (num_cnt = read_vector_float(nums, 100u, -1))
    {
    case -2: __m_exit(eINPUT_invalid);
    case 0: __m_exit(eDATA_insufficient);
    }
    int hist[11];
    create_histogram(nums, num_cnt, hist, 11);
    for (int* s = hist; s < hist + 11; ++s)
    {
        printf("%d ", *(s));
    }
    return 0;
}

int create_histogram(const float* vec, int size, int* out, int out_size)
{
    if (vec == null || size <= 0 || out == null || out_size <= 0)
    {
        return 1;
    }
    for (int* s = out; s < out + out_size; ++s)
    {
        *(s) = 0;
    }
    int temp;
    for (const float* s = vec; s < vec + size; ++s)
    {
        temp = (int)floorf(*(s));
        if (0 <= temp && temp <= out_size - 1)
        {
            ++(*(out + temp));
        }
    }
    return 0;
}
