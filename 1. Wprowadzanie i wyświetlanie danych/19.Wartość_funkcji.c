#include <stdio.h>

#define Y(x) (2*x*x*x + (-4)*x*x + 3*x -7)

int main()
{
    float x;
    printf("Input x value: ");
    scanf("%f", &x);
    printf("Value of y: %f", Y(x));
    return 0;
}
