#include <stdio.h>
#include <stdbool.h>
#include "my_utils.h"

int is_divisible_by_11(int number);

int main()
{
    int n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%s", is_divisible_by_11(n) ? "YES" : "NO");
    return 0;
}

int is_divisible_by_11(int number)
{
    if (number == 0) return true;
    else if (-11 < number && number < 11) return false;
    else return number > 0 ? is_divisible_by_11(number - 11) : is_divisible_by_11(number + 11);
}
