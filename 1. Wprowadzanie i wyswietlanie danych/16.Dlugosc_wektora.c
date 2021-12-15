#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    printf("Input c: ");
    scanf("%d", &c);

    printf("%.2f\n", sqrt(a * a + b * b + c * c));
    return 0;
}
