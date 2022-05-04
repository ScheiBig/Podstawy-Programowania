#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()

int sum(const float* tab, unsigned int size, float* result);
int avg(const float* tab, unsigned int size, float* result);
int read_vector_float(float* vec, int size, float stop_value);

int main()
{
    float nums[100];
    int num_cnt;
    print_ln("Enter an array:");
    switch (num_cnt = read_vector_float(nums, 100u, 0))
    {
    case -2: __m_exit(eINPUT_invalid); 
    case 0: __m_exit(eDATA_insufficient); 
    }
    float sum_r;
    sum(nums, (unsigned)num_cnt, &sum_r);
    float avg_r;
    avg(nums, (unsigned)num_cnt, &avg_r);
    printf_ln("Sum is: %.2f", sum_r);
    printf_ln("Avg is: %.2f", avg_r);

    return 0;
}

int sum(const float* tab, unsigned int size, float* result)
{
    if (tab == null || size == 0 || result == null)
    {
        return 1;
    }
    float ret = 0;
    for (const float* s = tab; s < tab + size; ++s)
    {
        ret += *(s);
    }
    *(result) = ret;
    return 0;
}

int avg(const float* tab, unsigned int size, float* result)
{
    if (result == null)
    {
        return 1;
    }
    float ret;
    if (sum(tab, size, &ret) == 1)
    {
        return 1;
    }
    *(result) = ret / (float)size;
    return 0;
}

int read_vector_float(float* vec, int size, float stop_value)
{
    if (vec == null || size <= 0) return -1;
    int i;
    float temp;
    for (i = 0; i < size; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %f", &temp) != 1)
        {
            return -2;
        }
        else if (double_almost_eq(temp, stop_value, 0.000001f))
        {
            return i;
        }
        else
        {
            *(vec + i) = temp;
        }
    }
    discard_stdin();

    return i;
}
