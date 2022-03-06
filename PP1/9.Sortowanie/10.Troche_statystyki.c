#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_utils.h"
#include "vector_utils.h"
#include "statistics.h"


#define DATA_none 3
#define DATA_invalid 2
#define INPUT_invalid 1

#define MAX_LEN 150
#define EOV 0

int main()
{
    int nums[MAX_LEN];
    int num_cnt;
    print_ln("Enter an array:");
    switch (num_cnt = read_vector(nums, MAX_LEN, EOV))
    {
    case vuDATA_invalid: { _e_exit(INPUT_invalid, "Incorrect input") }
    case 0: { _e_exit(DATA_none, "Not enough data available") }
    }

    printf_ln("%.2f", median(nums, num_cnt));
    printf_ln("%d", mode(nums, num_cnt));
    printf_ln("%.2f", average(nums, num_cnt));
    
    return 0;
}
