#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_utils.h"
#include "vector_utils.h"
#include "sort.h"


#define DATA_none 3
#define DATA_invalid 2
#define INPUT_invalid 1

#define MAX_LEN 50
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

    int dir;

    print_ln("Enter a sorting direction: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" %d", &dir) != 1)
    {
        _e_exit(INPUT_invalid, "Incorrect input")
    }

    switch (dir)
    {
    case ASCENDING: case DESCENDING:
        bubble_sort(nums, num_cnt, (enum direction)dir);
        break;
    default: { _e_exit(DATA_invalid, "Incorrect input data") }
    }


    return 0;
}
