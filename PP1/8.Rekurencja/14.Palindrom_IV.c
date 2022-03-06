#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_utils.h"

int is_palindrom_rec(const int tab[], int start_index, int end_index);
int read_vector(int vec[], int size, int stop_value);

#define DATA_invalid -2
#define VEC_invalid -1
#define DATA_none 2
#define INPUT_invalid 1

#define MAX_LEN 100
#define EOV -1

int main()
{
    int nums[MAX_LEN];
    int num_cnt;
    print_ln("Enter numbers:");
    switch (num_cnt = read_vector(nums, MAX_LEN, EOV))
    {
    case DATA_invalid: { _e_exit(INPUT_invalid, "Incorrect input") }
    case 0: { _e_exit(DATA_none, "Not enough data available") }
    }

    printf_ln("%s", is_palindrom_rec(nums, 0, (int)num_cnt - 1) ? "YES" : "NO");
    return 0;
}

int is_palindrom_rec(const int tab[], int start_index, int end_index)
{
    if (tab == NULL || start_index < 0 || start_index > end_index) return VEC_invalid;
    else if (start_index == end_index) return true;
    else if (tab[start_index] == tab[end_index])
    {
        if (end_index - start_index == 1) return true;
        else return is_palindrom_rec(tab, start_index + 1, end_index - 1);
    }
    else return false;
}

int read_vector(int vec[], int size, int stop_value)
{
    if (size <= 0) return VEC_invalid;
    int i;
    int temp;
    for (i = 0; i < size; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %d", &temp) != 1)
        {
            return DATA_invalid;
        }
        else if (temp == stop_value)
        {
            return i;
        }
        else
        {
            vec[i] = temp;
        }
    }
    char trash;
    do
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%c", &trash);
    } while (trash != '\n');

    return i;
}
