#include <stdio.h>

int main()
{
    char sign;
    int real, success;
    unsigned int imag;

    printf("Input complex number: ");
    success = scanf("%d%ci%u", &real, &sign, &imag);
    printf("%d%c%ui\n%d\n", real, sign, imag, success);

    return 0;
}
