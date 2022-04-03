#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

union bit_set
{
    u_int value;
    u_short words[2];
    u_char bytes[4];
    struct
    {
        unsigned char _0 : 1;
        unsigned char _1 : 1;
        unsigned char _2 : 1;
        unsigned char _3 : 1;
        unsigned char _4 : 1;
        unsigned char _5 : 1;
        unsigned char _6 : 1;
        unsigned char _7 : 1;
    } bits[4];
};

int main()
{
    union bit_set num;

    printf("Enter a number:\n");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%u", &(num.value)) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%u\n", num.value);
    
    for (int i = 0; i < 2; ++i)
    {
        printf("%hu ", *(num.words + i));
    }
    printf("\n");

    for (int i = 0; i < 4; ++i)
    {
        printf("%hhu ", *(num.bytes + i));
    }
    printf("\n");

    for (int i = 0; i < 4; ++i)
    {
        printf("%d%d%d%d%d%d%d%d ",
            (num.bits + i)->_7,
            (num.bits + i)->_6,
            (num.bits + i)->_5,
            (num.bits + i)->_4,
            (num.bits + i)->_3,
            (num.bits + i)->_2,
            (num.bits + i)->_1,
            (num.bits + i)->_0);
    }
    printf("\n");
    return 0;
}
