#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "my_utils_v2.h"
__include__discard_stdin()
#include "vector_utils.h"

int find_min(const int* tab, int size, int* min);

int main()
{
    int nums[100];
    int num_cnt;
    print_ln("Enter an array:");
    switch (num_cnt = read_vector(nums, 100, -1))
    {
    case -2: __m_exit(eINPUT_invalid);
    case 0: __m_exit(eDATA_insufficient);
    }
    discard_stdin();

    int min = INT_MAX;
    find_min(nums, num_cnt, &min);
    printf_ln("Min: %d", min);
    
    return 0;
}

int find_min(const int* tab, int size, int* min)
{
    if (tab == null || size <= 0 || min == null)
    {
        return 1;
    }
    int tmp_min = INT_MAX;
    for (const int* s = tab; s < tab + size; ++s)
    {
        cond_assign_g(tmp_min, *(s));
    }
    *(min) = tmp_min;
    return 0;
}
