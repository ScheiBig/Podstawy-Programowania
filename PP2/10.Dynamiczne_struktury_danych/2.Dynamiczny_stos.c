#include <stdlib.h>
#include <stdbool.h>

#include "stack2.h"
#include "my_utils_v3.h"

enum choice
{
    EXIT, PUSH, POP, EMPTY, DISPLAY
};

#define m1 "Stack is empty"

int main()
{
    p_stack stack;
    if (stack_init(&stack) != 0) { __m_exit(eMEMORY_cantallocate); }

    bool cont = true;
    int choice;
    int value;

    while (cont)
    {
        print_ln("Choose an operation: ");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &choice) != 1)
        {
            stack_destroy(&stack);
            __m_exit(eINPUT_invalid);
        }
        switch (choice)
        {
        case EXIT:
            cont = false;
            break;
        case PUSH:
            print_ln("Enter a value:");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", &value) != 1)
            {
                STACK.destroy(&stack);
                __m_exit(eINPUT_invalid);
            }
            if (STACK.push(stack, value) != 0)
            {
                STACK.destroy(&stack);
                __m_exit(eMEMORY_cantallocate);
            }
            break;
        case POP:
            value = STACK.pop(stack, &choice);
            if (choice != 0) { print_ln(m1); }
            else { printf_ln("%d", value); }
            break;
        case EMPTY:
            printf_ln("%d", STACK.empty(stack));
            break;
        case DISPLAY:
            if (STACK.empty(stack)) { print_ln(m1); }
            else { STACK.display(stack); }
            break;
        default: print_ln(eDATA_invalid);
        }

    }

    stack_destroy(&stack);
    return 0;
}
