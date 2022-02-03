#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_utils.h"
#include "sort_utils.h"


#define DATA_none 3
#define DATA_none_msg "Not enough data available"
#define DATA_invalid 2
#define DATA_invalid_msg "Incorrect input data"
#define INPUT_invalid 1
#define INPUT_invalid_msg "Incorrect input"

#define MAX_LEN 31
#define EOV 0

int sort_lowercase(char tab[]);

int main()
{
    char chars[MAX_LEN];
    print_ln("Enter a word:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", chars) != 1)
    {
        _e_exit(DATA_invalid, DATA_invalid_msg)
    }
    if (sort_lowercase(chars) == 1)
    {
        _e_exit(DATA_invalid, DATA_invalid_msg)
    }
    printf_ln("%s", chars);

    return 0;
}

int comp_asc(int a, int b)
{
    return a < b;
}

int sort_lowercase(char tab[])
{
    int size;
    for (size = 0; tab[size] != (char)0; ++size)
    {
        if (!is_lowercase(tab[size])) return 1;
    }
    return sort_c(tab, size, comp_asc);
}
