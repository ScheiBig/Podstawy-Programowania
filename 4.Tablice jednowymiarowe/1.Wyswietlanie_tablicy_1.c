#include <stdio.h>

int main() {

    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d %d %d %d %d %d %d %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7],
           nums[8], nums[9], nums[10]);

    for (int i = 0; i <= 10; ++i)
    { printf("%d\n", nums[i]); }

    return 0;
}
