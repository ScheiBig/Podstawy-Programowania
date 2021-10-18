#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[10], i = 0;
    printf("Input 10 numbers: \n");
    scanf("%d %d %d %d %d %d %d %d %d %d",
        nums+i++, nums+i++, nums+i++, nums+i++, nums+i++,
        nums+i++, nums+i++, nums+i++, nums+i++, nums+i++);
    i = 0;
    printf("Yours numbers average: %.4f", 
        (nums[i++] + nums[i++] + nums[i++] + nums[i++] + nums[i++]
         + nums[i++] + nums[i++] + nums[i++] + nums[i++] + nums[i++])
         / 10.0);

    return 0;
}
