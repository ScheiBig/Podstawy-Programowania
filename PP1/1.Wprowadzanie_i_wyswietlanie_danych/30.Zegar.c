#include <stdio.h>

int main()
{
    int sec;
    printf("Input number of seconds: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &sec);
    printf("%2.2d:%2.2d:%2.2d\n",
        (sec / 60) / 60,
        (sec / 60) % 60,
        sec % 60);
    return 0;
}
