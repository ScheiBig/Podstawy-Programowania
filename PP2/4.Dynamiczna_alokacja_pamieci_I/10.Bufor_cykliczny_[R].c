#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
#include "circular_buffer.h"

enum choice_e
{
    EXIT, PUSH_TAIL, REMOVE_TAIL, REMOVE_HEAD, PEEK_ALL, PEEK_EMPTY, PEEK_FULL
};

int main()
{
    print_ln("Enter initial capacity:");
    int init_capacity;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &init_capacity) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (init_capacity <= 1)
    {
        __m_exit(eDATA_invalid);
    }
    struct circular_buffer_t* cir_buf;
    if (circular_buffer_create_struct(&cir_buf, init_capacity) != 0)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    int choice;
    bool is_running = true;
    while (is_running)
    {
        print_ln("Choose action - <1>push tail, <2>remove tail, <3>remove head, <4>peek all, <5>peek empty, <6>peek full, <0>exit");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &choice) != 1)
        {
            circular_buffer_destroy_struct(&cir_buf);
            __m_exit(eINPUT_invalid);
        }
        switch (choice)
        {
        case EXIT:
            is_running = false;
            break;
        case PUSH_TAIL:
            print_ln("Enter a number:");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", &choice) != 1)
            {
                circular_buffer_destroy_struct(&cir_buf);
                __m_exit(eINPUT_invalid);
            }
            circular_buffer_push_back(cir_buf, choice);
            break;
        case REMOVE_TAIL:
            if (circular_buffer_empty(cir_buf))
            {
                print_ln("Buffer is empty");
            }
            else
            {
                printf_ln("%d", circular_buffer_pop_back(cir_buf, null));
            }
            break;
        case REMOVE_HEAD:
            if (circular_buffer_empty(cir_buf))
            {
                print_ln("Buffer is empty");
            }
            else
            {
                printf_ln("%d", circular_buffer_pop_front(cir_buf, null));
            }
            break;
        case PEEK_ALL:
            if (circular_buffer_empty(cir_buf))
            {
                print_ln("Buffer is empty");
            }
            else
            {
                circular_buffer_display(cir_buf);
            }
            break;
        case PEEK_EMPTY:
            printf_ln("%d", circular_buffer_empty(cir_buf));
            break;
        case PEEK_FULL:
            printf_ln("%d", circular_buffer_full(cir_buf));
            break;
        default:
            print_ln(eDATA_invalid);
            break;
        }
    }
    circular_buffer_destroy_struct(&cir_buf);
    return 0;
}
