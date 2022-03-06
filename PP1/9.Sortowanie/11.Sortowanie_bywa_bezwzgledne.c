#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_utils.h"
#include "vector_utils.h"
#include "sort_utils.h"


#define DATA_none 3
#define DATA_invalid 2
#define INPUT_invalid 1

#define MAX_LEN 150
#define EOV 0

int sort_by_abs(int tab[], int size);
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

    sort_by_abs(nums, num_cnt);
    display_vector(nums, num_cnt);

    return 0;
}

int comp_abs(int a, int b)
{
    return (abs(a) < abs(b));
}


int sort_by_abs(int tab[], int size)
{
    return sort(tab, size, comp_abs);
}
