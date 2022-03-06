#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_utils.h"
#include "vector_utils.h"

int bubble_sort(int tab[], int size);

// #define DATA_none 2
#define DATA_none 3
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

    bubble_sort(nums, num_cnt);

    return 0;
}

int bubble_sort(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int temp, mov;
    for (int i = size; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                ++mov;
            }
        }
        display_vector(tab, size);
        if (mov == 0) break;
    }
    return 0;
}
