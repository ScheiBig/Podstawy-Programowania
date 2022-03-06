#include <stdio.h>

int main()
{
    char let[5];
    printf("Input 5 letters: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf(" %c%c%c%c%c", let, let + 1, let + 2, let + 3, let + 4);

    int count = 0;

    if (let[0] == 'x' || let[0] == 'y' || let[0] == 'z' ||
        let[0] == '2' || let[0] == '7') ++count;
    if (let[1] == 'x' || let[1] == 'y' || let[1] == 'z' ||
        let[1] == '2' || let[1] == '7') ++count;
    if (let[2] == 'x' || let[2] == 'y' || let[2] == 'z' ||
        let[2] == '2' || let[2] == '7') ++count;
    if (let[3] == 'x' || let[3] == 'y' || let[3] == 'z' ||
        let[3] == '2' || let[3] == '7') ++count;
    if (let[4] == 'x' || let[4] == 'y' || let[4] == 'z' ||
        let[4] == '2' || let[4] == '7') ++count;

    printf("Found characters: %d\n", count);

    return 0;
}
