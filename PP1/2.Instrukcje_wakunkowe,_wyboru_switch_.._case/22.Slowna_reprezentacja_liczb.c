#include <stdio.h>

char dictionary[11][10] = { "zero", "jeden", "dwa", "trzy", "cztery",
    "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec" };

int main()
{
    int num;
    printf("Input your number: ");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    switch (scanf("%d", &num))
    {
    case 1:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    switch (num)
    {
    case 0:
        printf("%s\n", dictionary[0]);
        break;
    case 1:
        printf("%s\n", dictionary[1]);
        break;
    case 2:
        printf("%s\n", dictionary[2]);
        break;
    case 3:
        printf("%s\n", dictionary[3]);
        break;
    case 4:
        printf("%s\n", dictionary[4]);
        break;
    case 5:
        printf("%s\n", dictionary[5]);
        break;
    case 6:
        printf("%s\n", dictionary[6]);
        break;
    case 7:
        printf("%s\n", dictionary[7]);
        break;
    case 8:
        printf("%s\n", dictionary[8]);
        break;
    case 9:
        printf("%s\n", dictionary[9]);
        break;
    case 10:
        printf("%s\n", dictionary[10]);
        break;

    default:
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
