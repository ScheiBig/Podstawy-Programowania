#include <stdio.h>

char imie[31] = { 0 };

int main()
{
    printf("Enter your name: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%30s", imie);

    printf("Witaj %s!\n", imie);

    return 0;
}
