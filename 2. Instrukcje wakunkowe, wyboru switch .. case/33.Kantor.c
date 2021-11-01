#include <stdio.h>

#define e(x) (x / 4.2074)
#define f(x) (x / 4.7073)
#define d(x) (x / 3.5382)

int main()
{
    float amount;
    char currency;
    printf("Enter money amount: ");
    switch (scanf("%f", &amount) * (amount > 0))
    {
    case 1:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    printf("Enter desired currency: ");
    switch (scanf(" %c", &currency))
    {
    case 1:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    switch (currency)
    {
    case 'e':
        printf("%.2f", e(amount));
        break;
    case 'f':
        printf("%.2f", f(amount));
        break;
    case 'd':
        printf("%.2f", d(amount));
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    return 0;
}
