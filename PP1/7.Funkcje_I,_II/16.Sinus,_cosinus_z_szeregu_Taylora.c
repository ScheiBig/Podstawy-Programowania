#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_utils.h"

double mySin(double x, int n);
double myCos(double x, int n);

int main()
{
    int op;
    double angle;
    print_ln("Enter an angle:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%lf", &angle) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a number of iterations:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op) != 1 || op < 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%f %f", mySin(angle, op), myCos(angle, op));

    return 0;
}

double mySin(double x, int n)
{
    if (n < 0) return -1; // Returning value from codomain is extremely bad practice
    double num = x;
    double den = 1;
    double tay = num / den;
    for (int i = 1; i <= n; ++i)
    {
        num *= x * x * (-1);
        den *= (2 * i + 1) * 2 * i;
        tay += num / den;
    }
    return tay;
}

double myCos(double x, int n)
{
    if (n < 0) return -1; // see line 35
    double num = 1;
    double den = 1;
    // (num / den) is for the algorithm clarity, but YAY dante, magic numbers
    double tay = 1;
    for (int i = 1; i <= n; ++i)
    {
        num *= x * x * (-1);
        den *= 2 * i * (2 * i - 1);
        tay += num / den;
    }
    return tay;
}
