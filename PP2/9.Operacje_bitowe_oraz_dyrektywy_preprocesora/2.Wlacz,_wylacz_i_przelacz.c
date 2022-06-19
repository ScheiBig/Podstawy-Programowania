#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

#include "my_utils_v3.h"

int toggle_bit(uint32_t* pvalue, int b);
int set_bit(uint32_t* pvalue, int b);
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);

enum op_type_t
{
    op_toggle, op_set, op_clear, op_read
};

int main()
{
    uint32_t value;
    print_ln("Enter a value: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%u", &value) != 1) { __m_exit(eINPUT_invalid); }
    int bit;
    print_ln("Enter a bit number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &bit) != 1) { __m_exit(eINPUT_invalid); }
    else if (!is_num_in_range(bit, 0, (signed)sizeof(uint32_t) * 8 - 1)) { __m_exit(eBIT_outbounds); }
    int op;
    print_ln("Select operation (0-toggle, 1-set, 2-clear, 3-read):");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op) != 1) { __m_exit(eINPUT_invalid); }
    else if (!is_num_in_range(op, 0, 3)) { __m_exit(eOPERATION_invalid); }

    switch (op)
    {
    case op_toggle:
        toggle_bit(&value, bit);
        printf("%08x\n", value);
        break;
    case op_set:
        set_bit(&value, bit);
        printf("%08x\n", value);
        break;
    case op_clear:
        clear_bit(&value, bit);
        printf("%08x\n", value);
        break;
    case op_read:
        printf("%d\n", isset_bit(&value, bit));
        break;
    }

    return 0;
}

#define check if (!is_num_in_range(b, 0, (signed)sizeof(uint32_t) * 8 - 1) || pvalue == null) { return -1; }

int toggle_bit(uint32_t* pvalue, int b)
{
    check* pvalue ^= 0x1 << b;
    return 0;
}

int set_bit(uint32_t* pvalue, int b)
{
    check* pvalue |= 0x1 << b;
    return 0;
}

int clear_bit(uint32_t* pvalue, int b)
{
    check* pvalue &= ~(0x1 << b);
    return 0;
}

int isset_bit(const uint32_t* pvalue, int b)
{
    check return (*pvalue >> b) & 0x1;
}

