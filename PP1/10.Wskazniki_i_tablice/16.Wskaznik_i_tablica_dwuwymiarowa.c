#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int is_prime(int a);

int main()
{
    int nums[10][10];
    print_ln("Enter a matrix:");
    int temp;
    for (int i = 0; i < 10; ++i)
    {
        int j = 0;
        
        while (j < 10)
        {
            if (scanf("%d", &temp) != 1)
            {
                __m_exit(eINPUT_invalid);
            }
            else if (is_prime(temp))
            {
                *(*(nums + i) + j) = temp;
                ++j;
            }
        }
    }
    
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (i % 3 == 0 && j % 3 == 0)
            {
                printf("%d ", *(*(nums + i) + j));
            }
        }
    }
    return 0;
}

int is_prime(int a)
{
    // 6k +- 1 optimization
    if (a == 2 || a == 3)
    {
        return true;
    }
    if (a <= 1 || a % 2 == 0 || a % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= a; i += 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}