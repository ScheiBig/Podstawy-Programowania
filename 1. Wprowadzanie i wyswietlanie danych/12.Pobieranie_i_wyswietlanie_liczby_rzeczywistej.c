#include <stdio.h>

int main(int argc, char const *argv[])
{
    float floating;
    // fflush(stdin);
    printf("Please enter floating: ");
    scanf("%f", &floating);
    printf("%f\n%f", floating, floating * 10);
    return 0;
}