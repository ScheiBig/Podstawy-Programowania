#include <stdio.h>

int main(int argc, char const *argv[])
{
    int integer;
    fflush(stdin);
    scanf("%d", &integer);
    printf("%d\n%d", integer, integer * 10);
    return 0;
}
