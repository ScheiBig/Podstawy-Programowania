#include <stdio.h>

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

int main()
{
    int nums[10];

    printf("Enter 10 numbers:\n");
    for (size_t i = 0; i < A_SIZE(nums) / 2; ++i)
    {
        if (scanf("%d %d", nums + (2 * i), nums + (2 * i + 1)) != 2)
        {
            printf("Input data type error");
            return 1;
        }
    }

    for (size_t i = 0; i < A_SIZE(nums); ++i)
    {
        printf("%zu %d %s\n", i, nums[i], (nums[i] % 2) ? "odd" : "even");
    }

    return 0;
}