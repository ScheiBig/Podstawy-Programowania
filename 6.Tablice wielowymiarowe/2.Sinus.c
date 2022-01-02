#include <stdio.h>
#define _USE_MATH_DEFINES 1
#define __USE_MISC 1
#define __USE_XOPEN 1
#include <math.h>

#define ARR_ROWS 2
enum rows
{
    _x_, _y_
};

#define ARG_STEP_INV 100.0
#define ARR_COLS (2 * (int)ARG_STEP_INV + 1)

int main()
{
    double sin_x[ARR_ROWS][ARR_COLS] = { { 0.0 } };

    for (size_t i = 0; i < ARR_COLS; ++i)
    {
        sin_x[_x_][i] = i / ARG_STEP_INV;
        sin_x[_y_][i] = sin(i * M_PI / ARG_STEP_INV);
    }

    for (size_t i = 0; i < ARR_COLS; ++i)
    {
        printf("%7.4lf %7.4lf\n", sin_x[_x_][i], sin_x[_y_][i]);
    }

    return 0;
}
