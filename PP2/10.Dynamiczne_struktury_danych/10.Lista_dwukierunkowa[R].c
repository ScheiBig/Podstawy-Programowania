#include "doubly_linked_list.h"

#include "my_utils_v3.h"

enum choice
{
    EXIT,
    PUSH_B,
    POP_B,
    PUSH_F,
    POP_F,
    PUSH_I,
    POP_I,
    PEEK_B,
    PEEK_F,
    EMPTY,
    SIZE,
    CLEAR,
    PEEK_I,
    DISPLAY_F,
    DISPLAY_B
};

#define m1 "List is empty"
#define m2 "Index out of range"

int main()
{
    doubly_linked_list_s* list = LIST.create();
    if (list == null) { __m_exit(eMEMORY_cantallocate); }

    bool is_active = true;
    int option;
    int arg1;
    int arg2;

    while (is_active)
    {
        print_ln("Select an option: ");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &option) != 1)
        {
            LIST.clear(list);
            MEMORY.release(list);
            __m_exit(eINPUT_invalid);
        }
        while (getc(stdin) != '\n');

        switch (option)
        {
        case EXIT: {
            is_active = false;
            break;
        }
        case PUSH_B: {
            print_ln("Enter a value: ");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", &arg1) != 1)
            {
                LIST.clear(list);
                MEMORY.release(list);
                __m_exit(eINPUT_invalid);
            }
            while (getc(stdin) != '\n');
            if (LIST.push_back(list, arg1) == 2)
            {
                LIST.clear(list);
                MEMORY.release(list);
                __m_exit(eMEMORY_cantallocate);
            }
            break;
        }
        case POP_B: {
            arg1 = LIST.pop_back(list, &arg2);
            if (arg2 == 1) { print_ln(m1); }
            else { printf_ln("%d", arg1); }
            break;
        }
        case PUSH_F: {
            print_ln("Enter a value: ");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", &arg1) != 1)
            {
                LIST.clear(list);
                MEMORY.release(list);
                __m_exit(eINPUT_invalid);
            }
            while (getc(stdin) != '\n');
            if (LIST.push_front(list, arg1))
            {
                LIST.clear(list);
                MEMORY.release(list);
                __m_exit(eMEMORY_cantallocate);
            }
            break;
        }
        case POP_F: {
            arg1 = LIST.pop_front(list, &arg2);
            if (arg2 == 1) { print_ln(m1); }
            else { printf_ln("%d", arg1); }
            break;
        }
        case PUSH_I: {
            print_ln("Enter a value: ");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", &arg1) != 1)
            {
                LIST.clear(list);
                MEMORY.release(list);
                __m_exit(eINPUT_invalid);
            }
            while (getc(stdin) != '\n');
            print_ln("Enter an index: ");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", &arg2) != 1)
            {
                LIST.clear(list);
                MEMORY.release(list);
                __m_exit(eINPUT_invalid);
            }
            while (getc(stdin) != '\n');
            if (arg2 < 0)
            {
                print_ln(m2);
            }
            else
            {
                arg1 = LIST.insert(list, arg2, arg1);
                if (arg1 == 1)
                {
                    print_ln(m2);
                }
                else if (arg1 == 2)
                {
                    LIST.clear(list);
                    MEMORY.release(list);
                    __m_exit(eMEMORY_cantallocate);
                }
            }
            break;
        }
        case POP_I: {
            if (LIST.is_empty(list)) { print_ln(m1); }
            else
            {
                print_ln("Enter an index: ");
                //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
                if (scanf("%d", &arg2) != 1)
                {
                    LIST.clear(list);
                    MEMORY.release(list);
                    __m_exit(eINPUT_invalid);
                }
                while (getc(stdin) != '\n');
                if (arg2 < 0) { print_ln(m2); }
                else
                {
                    arg1 = LIST.remove(list, arg2, &arg2);
                    if (arg2 == 1) { print_ln(m2); }
                    else { printf_ln("%d", arg1); }
                }
            }
            break;
        }
        case PEEK_B: {
            if (LIST.is_empty(list)) { print_ln(m1); }
            else { printf_ln("%d", LIST.back(list, null)); }
            break;
        }
        case PEEK_F: {
            if (LIST.is_empty(list)) { print_ln(m1); }
            else { printf_ln("%d", LIST.front(list, null)); }
            break;
        }
        case EMPTY: {
            printf_ln("%d", LIST.is_empty(list));
            break;
        }
        case SIZE: {
            printf_ln("%d", LIST.size(list));
            break;
        }
        case CLEAR: {
            LIST.clear(list);
            break;
        }
        case PEEK_I: {
            if (LIST.is_empty(list)) { print_ln(m1); }
            else
            {
                print_ln("Enter an index: ");
                //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
                if (scanf("%d", &arg2) != 1)
                {
                    LIST.clear(list);
                    MEMORY.release(list);
                    __m_exit(eINPUT_invalid);
                }
                while (getc(stdin) != '\n');
                if (arg2 < 0) { print_ln(m2); }
                else
                {
                    arg1 = LIST.at(list, arg2, &arg2);
                    if (arg2 == 1) { print_ln(m2); }
                    else { printf_ln("%d", arg1); }
                }
            }
            break;
        }
        case DISPLAY_F: {
            if (LIST.is_empty(list)) { print_ln(m1); }
            else { LIST.display(list); }
            break;
        }
        case DISPLAY_B: {
            if (LIST.is_empty(list)) { print_ln(m1); }
            else { LIST.display_reverse(list); }
            break;
        }
        default: {
            print_ln(eDATA_invalid);
            break;
        }
        }
    }

    LIST.clear(list);
    MEMORY.release(list);

    return 0;
}