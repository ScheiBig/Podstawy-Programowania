#include <stdio.h>

int main()
{
    float amount;
    int months;

    printf("Input starting amount: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &amount) != 1 || amount < 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Input number of months: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &months) != 1 || months < 0)
    {
        printf("Incorrect input");
        return 1;
    }
    for (int i = 0; i < months; ++i)
    {
        amount *= 1.01f;
    }
    printf("Final amount: %.2f\n", amount);

    return 0;
}