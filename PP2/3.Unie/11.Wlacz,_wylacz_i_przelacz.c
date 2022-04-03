#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include <stdint.h>
#include <inttypes.h>

#include "my_utils_v2.h"

int toggle_bit(uint32_t* pvalue, int b);
int set_bit(uint32_t* pvalue, int b);
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);

enum op_e
{
    TOGGLE, SET, CLEAR, READ
};

int main()
{
    uint32_t num;
    int bit;
    int op;
    print_ln("Enter a number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%" SCNu32, &num) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    print_ln("Enter a bit number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &bit) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (0 > bit || bit > 31)
    {
        _m_exit(2, "Invalid bit index");
    }
    print_ln("Enter operation - [0]toggle, [1]set, [2]clear, [3]read:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (0 > op || op > 3)
    {
        _m_exit(2, "Invalid operation");
    }
    switch (op)
    {
    case TOGGLE:
        toggle_bit(&num, bit);
        break;
    case SET:
        set_bit(&num, bit);
        break;
    case CLEAR:
        clear_bit(&num, bit);
        break;
    case READ:
        printf("%d", isset_bit(&num, bit));
        return 0;
    default:
        break;
    }
    printf("%x", num);
    return 0;
}

int toggle_bit(uint32_t* pvalue, int b)
{
    if (pvalue == NULL || 0 > b || b > 31)
    {
        return -1;
    }
    if (isset_bit(pvalue, b))
    {
        clear_bit(pvalue, b);
    }
    else
    {
        set_bit(pvalue, b);
    }
    return 0;
}

int set_bit(uint32_t* pvalue, int b)
{
    if (pvalue == NULL || 0 > b || b > 31)
    {
        return -1;
    }
    if (!isset_bit(pvalue, b))
    {
        uint32_t t = 0x1;
        for (int i = 0; i < b; ++i)
        {
            t *= 2;
        }
        *(pvalue) += t;
    }
    return 0;
}

int clear_bit(uint32_t* pvalue, int b)
{
    if (pvalue == NULL || 0 > b || b > 31)
    {
        return -1;
    }
    if (isset_bit(pvalue, b))
    {
        uint32_t t = 0x1;
        for (int i = 0; i < b; ++i)
        {
            t *= 2;
        }
        *(pvalue) -= t;
    }
    return 0;
}

int isset_bit(const uint32_t* pvalue, int b)
{
    if (pvalue == NULL || 0 > b || b > 31)
    {
        return -1;
    }
    uint32_t t = *pvalue;
    for (int i = 0; i < b; ++i)
    {
        t /= 2;
    }
    return t % 2;
}
