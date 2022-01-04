#include <stdio.h>

int main()
{
    int num1, num2, success;
    printf("Input two integer numbers separated with space: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d %d", &num1, &num2);
    if (success != 2)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("%d\n", num1 + num2);
    return 0;
}
