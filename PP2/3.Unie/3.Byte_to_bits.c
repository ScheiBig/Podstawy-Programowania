#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "bit_set.h"

int main()
{
    union bit_set num;

    printf("Enter a number:\n");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%hhu", &(num.byte)) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d %d %d %d %d %d %d %d",
        num.bits._7,
        num.bits._6,
        num.bits._5,
        num.bits._4,
        num.bits._3,
        num.bits._2,
        num.bits._1,
        num.bits._0);
    return 0;
}
