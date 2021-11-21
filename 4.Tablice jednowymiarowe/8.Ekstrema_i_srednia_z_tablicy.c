#include <stdio.h>
#include <limits.h>

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

int main()
{
    int nums[10], min = INT_MAX, max = INT_MIN;
    long sum = 0;

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
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max : nums[i];
        sum += nums[i];
    }

    double avg = sum / 10.0;
    printf("%.4lf\n%d\n%d\n", avg, max, min);

    return 0;
}