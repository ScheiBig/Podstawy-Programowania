#include <stdlib.h>
#include <stdbool.h>

#include "stack3.h"
#include "my_utils_v3.h"

int main(int argc, char const* argv[])
{
    if (argc <= 1) { __m_exit(eARGS_insufficient); }

    stack_s* stack;
    for (int i = 1; i < argc; ++i)
    {
        switch (STACK.load(&stack, *(argv + i)))
        {
        case 1: {
            STACK.destroy(&stack);
            __m_exit(eERROR_unknown);
        }
        case 2: {
            printf_ln("Couldn't open file %s", *(argv + i));
            goto continue_for;
        }
        case 3: {
            STACK.destroy(&stack);
            __m_exit(eMEMORY_cantallocate);
        }
        }
        switch (STACK.save(stack, *(argv + i)))
        {
        case 1: {
            STACK.destroy(&stack);
            __m_exit(eERROR_unknown);
        }
        case 2: {
            STACK.destroy(&stack);
            __m_exit(eFILE_cantcreate);
        }
        }

        printf_ln("File %s saved", *(argv + i));
        STACK.destroy(&stack);

        continue_for: {}
    }
    return 0;
}
