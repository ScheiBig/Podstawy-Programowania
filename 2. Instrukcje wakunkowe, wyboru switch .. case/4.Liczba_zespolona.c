#include <stdio.h>

int main()
{
    int real, imag, success;
    char sign;

    printf("Input complex number: ");
    success = scanf("%d%ci%d", &real, &sign, &imag);
    if (success != 3 || (sign != '+' && sign != '-') || imag < 0)
    {
        printf("Incorrect input\n");
        return 1;
    }
    imag = (sign == '-') ? (-imag) : imag;

    printf("Real part: %d\n", real);
    printf("Imaginary part: %d\n", imag);
    return 0;
}
