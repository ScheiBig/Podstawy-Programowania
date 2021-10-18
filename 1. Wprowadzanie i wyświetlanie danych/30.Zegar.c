#include <stdio.h>

int main()
{
    int sec;
    printf("Input number of seconds: ");
    scanf("%d", &sec);
    printf("%2.2d:%2.2d:%2.2d\n",
        (sec / 60) / 60,
        (sec / 60) % 60,
        sec % 60);
    return 0;
}
