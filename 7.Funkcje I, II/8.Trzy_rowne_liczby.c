#include <stdio.h>
#include "my_utils.h"
#include <math.h>

int compare(int, int, int);

int main()
{
    int val1, val2, val3;
    print_ln("Enter your numbers:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d-%d-%d", &val1, &val2, &val3) != 3)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%s", compare(val1, val2, val3) ? "EQUAL" : "NOT EQUAL");

    return 0;
}

int compare(int v1, int v2, int v3)
{
    return v1 == v2 && v2 == v3 && v3 == v1;
}
