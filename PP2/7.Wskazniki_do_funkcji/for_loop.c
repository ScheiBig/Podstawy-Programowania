#include "for_loop.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double accu;

bool is_accu_start = false;

void for_loop(double start, double step, double end_ex, iteration lambda)
{
    if (lambda == NULL || step > 0 && start > end_ex || step < 0 && start < end_ex || step == 0)
    {
        return;
    }
    
    if (!is_accu_start)
    {
        is_accu_start = true;
        accu = 0;
    }

    if (step > 0 && start < end_ex || step < 0 && start > end_ex)
    {
        lambda(start);
        for_loop(start + step, step, end_ex, lambda);
    }

    is_accu_start = false;
}

void print_value(double value)
{
    printf("%lf ", value);
}

void print_accumulated(double value)
{
    accu += value;
    printf("%lf ", accu);
}

void print_square(double value)
{
    printf("%lf ", value * value);
}

void print_abs(double value)
{
    printf("%lf ", fabs(value));
}
