#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Input your numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", (a >= b) + (a >= c));
    return 0;
}
