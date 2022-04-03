#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "byte_set.h"

int main()
{
    union byte_set num;
    printf("Enter a number:\n");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &(num.value)) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%hhu %hhu %hhu %hhu", *num.bytes, *(num.bytes + 1), *(num.bytes + 2), *(num.bytes + 3));
    return 0;
}
