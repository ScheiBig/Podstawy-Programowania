#include <stdio.h>

int main() {

    int nums[11];

    for (int i = 0; i<= 10; ++i)
    { nums[i] = i; }

    for (int i = 0; i <= 10; ++i)
    { printf("%d ", nums[i]); }

    printf("\n");

    return 0;
}
