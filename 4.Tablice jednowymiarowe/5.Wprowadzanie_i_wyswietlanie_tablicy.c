#include <stdio.h>

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

int main()
{
    double nums[10];

    printf("Enter 10 numbers:\n");
    for (size_t i = 0; i < A_SIZE(nums) / 2; ++i)
    {
        if (scanf("%lf %lf", nums + (2 * i), nums + (2 * i + 1)) != 2)
        {
            printf("Input data type error");
            return 1;
        }
    }

    for (size_t i = 0; i < A_SIZE(nums); ++i)
    {
        printf("%zu %lf\n", i, nums[i]);
    }

    return 0;
}