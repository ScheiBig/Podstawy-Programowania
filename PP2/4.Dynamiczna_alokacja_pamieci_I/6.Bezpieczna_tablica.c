#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
#include "array.h"

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
    struct array_t arr;
    if (array_create(&arr, init_capacity) != 0)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    int choice;
    print_ln("Enter numbers to add:");
    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &choice) != 1)
        {
            array_destroy(&arr);
            __m_exit(eINPUT_invalid);
        }
        if (choice == 0)
        {
            break;
        }
        if (array_push_back(&arr, choice) != 0)
        {
            print_ln("Buffer is full");
            break;
        }
    }
    if (arr.size > 0)
    {
        array_display(&arr);
    }
    else
    {
        print_ln("Buffer is empty");
    }
    array_destroy(&arr);
    return 0;
}