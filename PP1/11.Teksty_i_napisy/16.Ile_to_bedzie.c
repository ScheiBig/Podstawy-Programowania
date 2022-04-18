#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "my_utils_v2.h"

int validate_expression(const char* expr);
int _validate_expression(const char* expr);
int calculate(const char* expr, float* result);
int _calculate(const char* expr, float* result);

int main()
{
    char expr[201];
    print_ln("Enter an expression:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%200s", expr);
    if (validate_expression(expr) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    float res;
    if (calculate(expr, &res) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    printf("%.2f", res);

    return 0;
}

int validate_expression(const char* expr)
{
    if (expr == null)
    {
        return -1;
    }
    size_t size = strlen(expr);
    if (!(is_digit(*(expr)) && is_digit(*(expr + size - 1))))
    {
        return 0;
    }
    return _validate_expression(expr);
}

int _validate_expression(const char* expr)
{
    if (*(expr) == str_term)
    {
        return 1;
    }
    switch (*(expr))
    {
    case '+': case '-': case '*': case '/':
        if (!is_digit(*(expr + 1)))
        {
            return 0;
        }
        break;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        break;
    default:
        return 0;
    }
    return _validate_expression(expr + 1);
}

int calculate(const char* expr, float* result)
{
    if (expr == null || result == null || validate_expression(expr) != 1)
    {
        return 0;
    }
    int num = atoi(expr);
    *(result) = (float)num;
    const char* next_expr = expr + strspn(expr, "0123456789");
    return _calculate(next_expr, result);
}

int _calculate(const char* expr, float* result)
{
    if (*(expr) == str_term)
    {
        return 1;
    }
    char op = *(expr);
    int num = atoi(expr + 1);
    if (op == '/' && num == 0)
    {
        return 0;
    }
    switch (op)
    {
    case '+':
        *(result) += (float)num;
        break;
    case '-':
        *(result) -= (float)num;
        break;
    case '*':
        *(result) *= (float)num;
        break;
    case '/':
        *(result) /= (float)num;
        break;
    default:
        return 0;
    }
    const char* next_expr = expr + 1 + strspn(expr + 1, "0123456789");
    return _calculate(next_expr, result);
}
