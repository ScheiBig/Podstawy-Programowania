#include <stdio.h>
#include <math.h>


int main()
{
    float current;
    long double product = 1;

    while (INFINITY)
    {
        printf("Input a number: ");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%f", &current) != 1)
        {
            printf("Incorrect input");
            return 0;
        }
        product *= current;
        printf("Product: %.2Lf\n", product);
    }
}