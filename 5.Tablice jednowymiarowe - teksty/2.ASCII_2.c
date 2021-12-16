#include <stdio.h>

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

char tekst[] = { 'T','o',' ','j','e','s','t',' ','t','e','k','s','t','\x0' };

int main()
{
    for (size_t i = 0; i < A_SIZE(tekst) - 1; ++i)
    {
        putc(tekst[i], stdout);
        printf(" %d %c\n", (int)tekst[i], tekst[i]);
    }

    return 0;
}
