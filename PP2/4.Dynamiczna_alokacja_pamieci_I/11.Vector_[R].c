#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
#include "vector.h"

enum choice_e
{
    EXIT, PUSH, REMOVE_ALL
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
    struct vector_t* vec;
    if (vector_create_struct(&vec, init_capacity) != 0)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    int choice;
    bool is_running = true;
    while (is_running)
    {
        print_ln("Choose action - [1]push, [2]remove all, [0]exit");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &choice) != 1)
        {
            vector_destroy_struct(&vec);
            __m_exit(eINPUT_invalid);
        }
        switch (choice)
        {
        case EXIT:
            is_running = false;
            break;
        case PUSH:
            print_ln("Enter numbers to add:");
            while (true)
            {
                //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
                if (scanf("%d", &choice) != 1)
                {
                    vector_destroy_struct(&vec);
                    __m_exit(eINPUT_invalid);
                }
                if (choice == 0)
                {
                    break;
                }
                if (vector_push_back(vec, choice) != 0)
                {
                    print_ln(eMEMORY_cantallocate);
                    break;
                }
            }
            if (vec->size > 0)
            {
                vector_display(vec);
            }
            else
            {
                print_ln("Buffer is empty");
            }
            break;
        case REMOVE_ALL:
            print_ln("Enter numbers to remove:");
            while (true)
            {
                //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
                if (scanf("%d", &choice) != 1)
                {
                    vector_destroy_struct(&vec);
                    __m_exit(eINPUT_invalid);
                }
                if (choice == 0)
                {
                    break;
                }
                vector_erase(vec, choice);
            }

            if (vec->size > 0)
            {
                vector_display(vec);
            }
            else
            {
                print_ln("Buffer is empty");
            }
            break;
        default:
            print_ln(eDATA_invalid);
            break;
        }
    }
    vector_destroy_struct(&vec);
    return 0;
}
