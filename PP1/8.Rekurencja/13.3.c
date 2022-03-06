#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_utils.h"

int sum_of_digits(long long number);
int is_divisible_by_3(int number);

int main()
{
    long long num;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%lld", &num) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%s", is_divisible_by_3(sum_of_digits(num)) ? "YES" : "NO");
    return 0;
}

#define mod10(num) (num - 10 * (num / 10))

int sum_of_digits(long long number)
{
    if (number < 0) return sum_of_digits(-number);
    else if (number < 10) return (int)number;
    else
    {
        return (int)mod10(number) + sum_of_digits(number / 10);
    }
}

int is_divisible_by_3(int number)
{
    if (number < 0) return is_divisible_by_3(-number);
    else if (number > 10) return is_divisible_by_3(sum_of_digits(number));
    else
    {
        switch (number)
        {
        case 0:case 3:case 6:case 9:
            return true;
        default:
            return false;
        }
    }
}
