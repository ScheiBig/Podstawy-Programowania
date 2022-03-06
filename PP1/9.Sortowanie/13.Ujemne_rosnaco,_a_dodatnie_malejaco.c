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

int sort_negative_asc_positive_desc(int tab[], int size);

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

    sort_negative_asc_positive_desc(nums, num_cnt);
    display_vector(nums, num_cnt);

    return 0;
}

int comp_asc(int a, int b)
{
    return a < b;
}

int comp_desc(int a, int b)
{
    return a > b;
}

int sort_negative_asc_positive_desc(int tab[], int size)
{
    int ret = sort(tab, size, comp_asc);
    int piv_i;
    for (piv_i = 0; piv_i < size && tab[piv_i] < 0; ++piv_i);
    if (piv_i < size) ret += sort(tab + piv_i, size - piv_i, comp_desc);
    return !!ret;
}
