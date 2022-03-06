#include <stdio.h>

typedef unsigned long long int ulonger;

int main()
{
    int number;
    printf("Enter your number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &number) != 1 || number < 0 || number > 21)
    {
        printf("Incorrect input");
        return 1;
    }
    ulonger factorial = 1;
    for (int i = 1; i < number; factorial *= ++i);
    printf("%llu", factorial);

    return 0;
}