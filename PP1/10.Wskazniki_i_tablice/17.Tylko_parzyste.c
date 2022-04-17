#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
#include "vector_utils.h"
#include "functions.h"

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
    
    int cur_num = get_next_number(nums, num_cnt, ALL_ODD);
    if (cur_num == -1)
    {
        print_ln("Nothing to show");
    }
    else
    {
        do
        {
            printf("%d ", cur_num);
        } while ((cur_num = get_next_number(null, 0, ALL_ODD)) != -1);
        print_n();
    }
    cur_num = get_next_number(nums, num_cnt, ALL_EVEN);
    if (cur_num == -1)
    {
        print_ln("Nothing to show");
    }
    else
    {
        do
        {
            printf("%d ", cur_num);
        } while ((cur_num = get_next_number(null, 0, ALL_EVEN)) != -1);
        print_n();
    }
    cur_num = get_next_number(nums, num_cnt, MIX);
    if (cur_num == -1)
    {
        print_ln("Nothing to show");
    }
    else
    {
        do
        {
            printf("%d ", cur_num);
        } while ((cur_num = get_next_number(null, 0, MIX)) != -1);
        print_n();
    }

    return 0;
}

