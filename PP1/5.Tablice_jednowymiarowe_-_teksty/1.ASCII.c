#include <stdio.h>

int ascii[26];

int main()
{
    for (int i = 65; i <= 90; ++i)
    {
        ascii[i - 65] = i;
    }

    for (int i = 0; i < 26; ++i)
    {
        printf("%d %c %c\n", ascii[i], (char)ascii[i], (char)ascii[i] + 32);
    }

    return 0;
}
