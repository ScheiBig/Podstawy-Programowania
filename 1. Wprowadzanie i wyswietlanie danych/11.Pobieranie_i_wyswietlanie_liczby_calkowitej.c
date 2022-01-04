#include <stdio.h>

int main(int argc, char const* argv[])
{
    int integer;
    //cppcheck-suppress fflushOnInputStream
    fflush(stdin);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &integer);
    printf("%d\n%d", integer, integer * 10);
    return 0;
}
