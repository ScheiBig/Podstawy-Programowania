#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "word_set.h"

int main()
{
    union word_set num;
    printf("Enter a number:\n");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &(num.value)) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%hu %hu", *num.words, *(num.words + 1));
    return 0;
}
