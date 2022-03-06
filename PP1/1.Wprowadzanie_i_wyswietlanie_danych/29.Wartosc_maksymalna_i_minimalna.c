#include <stdio.h>

int main()
{
    int nums[2];
    printf("Input your numbers: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d %d", nums, nums + 1);

    int comp = nums[0] - nums[1];
    int sign = ((unsigned)comp >> (sizeof(int) * 8 - 1)) & 0x1;

    printf("Maximum: %d\nMinimum: %d\n",
        nums[sign], nums[1 - sign]);

    return 0;
}
