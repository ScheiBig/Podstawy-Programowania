#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, A, B;
    printf("Insert first side: ");
    scanf("%f", &a);
    printf("Insert second side: ");
    scanf("%f", &b);

    c = sqrt(a*a + b*b);
    A = acos((b*b+c*c-a*a)/(2*b*c)) * 180/M_PI;
    B = acos((a*a+c*c-b*b)/(2*a*c)) * 180/M_PI;

    printf("Hypotenuse value: %.2f\n", c);
    printf("First angle: %.2f\n", A);
    printf("Second angle: %.2f\n", B);

    return 0;
}
