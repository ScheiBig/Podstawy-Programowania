#include <stdio.h>

int main()
{
    char let[6];
    printf("Input 5 letters: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf(" %c%c%c%c%c", let, let + 1, let + 2, let + 3, let + 4);

    int diff = (int)('a' - 'A');

    if (let[0] >= 'a' && let[0] <= 'z') let[0] -= diff;
    if (let[1] >= 'a' && let[1] <= 'z') let[1] -= diff;
    if (let[2] >= 'a' && let[2] <= 'z') let[2] -= diff;
    if (let[3] >= 'a' && let[3] <= 'z') let[3] -= diff;
    if (let[4] >= 'a' && let[4] <= 'z') let[4] -= diff;

    let[5] = (char)0;

    printf("%s\n", let);

    return 0;
}
