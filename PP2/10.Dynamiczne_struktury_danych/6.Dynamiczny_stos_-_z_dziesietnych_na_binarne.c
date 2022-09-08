#include "stack2.h"

#include <inttypes.h>

#include "my_utils_v3.h"

int main()
{
    stack_s* stack;
    if (STACK.init(&stack) != 0) { __m_exit(eMEMORY_cantallocate); }

    uint64_t value;
    print_ln("Enter a number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%" SCNu64, &value) != 1)
    {
        STACK.destroy(&stack);
        __m_exit(eINPUT_invalid);
    }

    if (value == 0)
    {
        print_ln("0");
        STACK.destroy(&stack);
        return 0;
    }

    while (value != 0)
    {
        if (STACK.push(stack, value % 2) != 0)
        {
            STACK.destroy(&stack);
            __m_exit(eMEMORY_cantallocate);
        }
        value /= 2;
    }
    
    STACK.display(stack);
    
    STACK.destroy(&stack);
    return 0;
}