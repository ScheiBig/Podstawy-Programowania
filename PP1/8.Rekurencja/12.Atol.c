#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my_utils.h"

unsigned long long my_atol_rec(const char tab[], int size);
bool is_number(const char tab[], int size);

int main()
{
    char num[16] = { (char)0 };
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%15s", num) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    else if (!is_number(num, 15))
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%llu", my_atol_rec(num, 15));
    return 0;
}

unsigned long long my_atol_rec(const char tab[], int size)
{
    if (size < 1 || !is_digit(tab[0]) || !(is_digit(tab[size - 1])|| tab[size-1] == (char)0)) return 0LL;
    else if (size == 1) return (unsigned)ctoi(tab[0]);
    else if (tab[size - 1] == (char)0) return my_atol_rec(tab, size - 1);
    else return (unsigned)ctoi(tab[size - 1]) + (10 * my_atol_rec(tab, size - 1));
}

bool is_number(const char tab[], int size)
{
    if (size == 0) return (is_digit(tab[0]));
    else
    {
        if (is_digit(tab[size - 1]) || tab[size - 1] == (char)0)
        {
            return is_number(tab, size - 1);
        }
        else return false;
    }
}
