#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#include "my_utils_v3.h"

int stats(int* sum, float* avg, int num, ...);

int main()
{
    int num;
    int nums[3];
    print_ln("Enter number of elements:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &num) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (!is_num_in_range(num, 1, 3))
    {
        __m_exit(eDATA_invalid);
    }


    printf_ln("Enter %d numbers", num);
    switch (num)
    {
    case 3:
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", nums + 2) != 1)
        {
            __m_exit(eINPUT_invalid);
        }
        __attribute__((fallthrough));
    case 2:
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", nums + 1) != 1)
        {
            __m_exit(eINPUT_invalid);
        }
        __attribute__((fallthrough));
    case 1:

        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", nums) != 1)
        {
            __m_exit(eINPUT_invalid);
        }
        break;
    default: break;
    }

    int sum;
    float avg;

    switch (num)
    {
    case 3:
        stats(&sum, &avg, 3, *nums, *(nums + 1), *(nums + 2));
        break;
    case 2:
        stats(&sum, &avg, 2, *nums, *(nums + 1));
        break;
    case 1:
        stats(&sum, &avg, 1, *nums);
        break;
    default: break;
    }

    printf_ln("%d, %f", sum, avg);

    return 0;
}

int stats(int* sum, float* avg, int num, ...)
{
    if (sum == null || avg == null || num <= 0) { return 1; }
    *sum = 0;
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; ++i) { *sum += va_arg(args, int); }
    *avg = (float)*sum / (float)num;
    va_end(args);
    return 0;
}