#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_utils.h"
#include "vector_utils.h"


#define DATA_none 3
#define DATA_none_msg "Not enough data available"
#define DATA_invalid 2
#define DATA_invalid_msg "Incorrect input data"
#define INPUT_invalid 1
#define INPUT_invalid_msg "Incorrect input"

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

    int offset;
    print_ln("Enter a offset:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" %d", &offset) != 1)
    {
        _e_exit(INPUT_invalid, INPUT_invalid_msg)
    }

    int direction;
    print_ln("Enter a direction:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" %d", &direction) != 1)
    {
        _e_exit(INPUT_invalid, INPUT_invalid_msg)
    }
    switch (direction)
    {
    case ROTATE_RIGHT: case ROTATE_LEFT: break;
    default: { _e_exit(DATA_invalid, DATA_invalid_msg) }
    }

    shift(nums, num_cnt, offset, (enum direction)direction);
    display_vector(nums, num_cnt);

    return 0;
}