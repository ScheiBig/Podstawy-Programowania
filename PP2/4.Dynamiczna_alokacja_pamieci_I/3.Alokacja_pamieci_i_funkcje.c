#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

float* create_array(int N);

int main()
{
    print_ln("Enter initial capacity:");
    int init_capacity;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &init_capacity) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (init_capacity <= 1)
    {
        __m_exit(eDATA_invalid);
    }
    float* nums = create_array(init_capacity);
    if (nums == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter numbers:");
    for (int i = 0; i < init_capacity; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%f", nums+i) != 1)
        {
            free(nums);
            __m_exit(eINPUT_invalid);
        }
    }

    for (int i = init_capacity - 1; i >= 0; --i)
    {
        printf("%f ", *(nums + i));
    }

    free(nums);
    return 0;
}

float* create_array(int N)
{
    if (N <= 0)
    {
        return null;

    }
    return (float*)malloc((unsigned)N * sizeof(float));
}