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

int sort_by_distance(int tab[], int size, int v);

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

    int val;
    print_ln("Enter a value:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" %d", &val) != 1)
    {
        _e_exit(INPUT_invalid, "Incorrect input")
    }

    sort_by_distance(nums, num_cnt, val);
    display_vector(nums, num_cnt);

    return 0;
}

int _v_;

int comp_dist(int a, int b)
{
    return (abs(a - _v_) < abs(b - _v_));
}

int sort_by_distance(int tab[], int size, int v)
{
    _v_ = v;
    return sort(tab, size, comp_dist);
}
