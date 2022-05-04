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

int main()
{
    float nums[100];
    int num_cnt;
    print_ln("Enter number count:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &num_cnt) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (0 >= num_cnt || num_cnt > 100)
    {
        __m_exit(eDATA_invalid);
    }
    float temp;
    print_ln("Enter an array:");
    for (int i = 0; i < num_cnt; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %f", &temp) != 1)
        {
            __m_exit(eINPUT_invalid);
        }
        else
        {
            *(nums + i) = temp;
        }
    }
    discard_stdin();
    for (float* s = nums + num_cnt - 1; s >= nums; --s)
    {
        printf("%f ", *(s));
    }
    print_n();
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
