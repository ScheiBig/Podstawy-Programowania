#include <stdio.h>

int main()
{
    int num1, num2, comp;
    printf("Input two numbers: ");
    switch (scanf("%d %d", &num1, &num2))
    {
    case 2:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    comp = (num1 < num2) * 1 + (num1 > num2) * 2;

    switch (comp)
    {
    case 1:
        printf("%d\n%d\n", num2, num1);
        break;
    case 0:
        printf("%d\n%d\n", num2, num1);
        break;
    case 2:
        printf("%d\n%d\n", num1, num2);
        break;
    }
    return 0;
}
