#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int add(const int* first, const int* second, int* result);
int subtract(const int* first, const int* second, int* result);
int multiply(const int* first, const int* second, int* result);
int divide(const int* first, const int* second, float* result);

int main()
{
    int num_1;
    int num_2;
    int num_3;
    float num_4;
    char op;
    print_ln("Enter an expression:");
    if (scanf("%d%c%d", &num_1, &op, &num_2) != 3)
    {
        __m_exit(eINPUT_invalid);
    }
    switch (op)
    {
        case '+':
            add(&num_1, &num_2, &num_3);
            break;
        case '-':
            subtract(&num_1, &num_2, &num_3);
            break;
        case '*':
            multiply(&num_1, &num_2, &num_3);
            break;
        case '/':
            if (num_2 == 0)
            {
                __m_exit(eOPERATION_invalid);
            }
            divide(&num_1, &num_2, &num_4);
            break;
        default: __m_exit(eINPUT_invalid);
    }
    if (op == '/')
    {
        printf("%f", num_4);
    }
    else
    {
        printf("%d", num_3);
    }
    return 0;
}

int add(const int* first, const int* second, int* result)
{
    if (first == null || second == null || result == null)
    {
        return 1;
    }
    *(result) = (*(first)) + (*(second));
    return 0;
}

int subtract(const int* first, const int* second, int* result)
{
    if (first == null || second == null || result == null)
    {
        return 1;
    }
    *(result) = (*(first)) - (*(second));
    return 0;
}

int multiply(const int* first, const int* second, int* result)
{
    if (first == null || second == null || result == null)
    {
        return 1;
    }
    *(result) = (*(first)) * (*(second));
    return 0;
}

int divide(const int* first, const int* second, float* result)
{
    if (first == null || second == null || result == null)
    {
        return 1;
    }
    if (*second == 0)
    {
        *(result) = 0;
        return 1;
    }
    *(result) = (float)(*(first)) / (*(second));
    return 0;
}
