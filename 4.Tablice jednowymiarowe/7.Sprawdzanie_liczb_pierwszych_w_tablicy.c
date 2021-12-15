#include <stdio.h>
#include <math.h>

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

typedef enum NumType
{
    nt_prime, nt_composite, nt_other
} num_type;

num_type checkPrime(int num)
{
    if (num <= 1)
    {
        return nt_other;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (i != num && num % i == 0)
        {
            return nt_composite;
        }
    }
    return nt_prime;
}

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
        printf("%zu %d ", i, nums[i]);
        switch (checkPrime(nums[i]))
        {
        case nt_prime:
        {
            printf("prime\n");
            break;
        }
        case nt_composite:
        {
            printf("composite\n");
            break;
        }
        case nt_other:
        {
            printf("other\n");
            break;
        }
        }
    }

    return 0;
}