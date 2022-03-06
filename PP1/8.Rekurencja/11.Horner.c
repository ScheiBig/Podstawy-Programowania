#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_utils.h"

int read_vector_double(double vec[], int size, double stop_value);
double horner(double a[], double x, int n);

#define DATA_invalid -2
#define ARG_invalid -1
// #define DATA_none 2
#define DATA_none 3
#define INPUT_invalid 1

#define MAX_LEN 100
#define EOV 0

int main()
{
    double nums[MAX_LEN], x;
    int num_cnt;
    print_ln("Enter coeffivients:");
    switch (num_cnt = read_vector_double(nums, MAX_LEN, EOV))
    {
    case DATA_invalid: { _e_exit(INPUT_invalid, "Incorrect input") }
    case 0: { _e_exit(DATA_none, "Not enough data available") }
    }
    print_ln("Enter a x:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%lf", &x) != 1) { _e_exit(INPUT_invalid, "Incorrect input") }

    printf_ln("%.2lf", horner(nums, x, num_cnt));
    return 0;
}

int read_vector_double(double vec[], int size, double stop_value)
{
    if (size <= 0) return ARG_invalid;
    int i;
    double temp;
    for (i = 0; i < size; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %lf", &temp) != 1)
        {
            return DATA_invalid;
        }
        else if (double_almost_eq(temp, stop_value, 0.00001))
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

double horner(double a[], double x, int n)
{
    if (n < 1) return ARG_invalid;
    else if (n == 1) return a[0];
    else return a[n - 1] + x * horner(a, x, n - 1);
}
