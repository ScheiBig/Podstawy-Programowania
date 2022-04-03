#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "my_utils_v2.h"
#include "my_exit.h"
#include "my_file.h"

int main()
{
    register_exit_handler(close_file_pointers);
    FILE* file_0 = register_file_pointer(fopen("0.txt", "w"));
    if (file_0 == NULL)
    {
        _mh_exit(eFILE_cantcreate_eno, eFILE_cantcreate)
    }
    FILE* file_2 = register_file_pointer(fopen("2.txt", "w"));
    if (file_2 == NULL)
    {
        _mh_exit(eFILE_cantcreate_eno, eFILE_cantcreate)
    }
    FILE* file_3 = register_file_pointer(fopen("3.txt", "w"));
    if (file_3 == NULL)
    {
        _mh_exit(eFILE_cantcreate_eno, eFILE_cantcreate)
    }
    FILE* file_5 = register_file_pointer(fopen("5.txt", "w"));
    if (file_5 == NULL)
    {
        _mh_exit(eFILE_cantcreate_eno, eFILE_cantcreate)
    }

    print_ln("Enter numbers");
    int number;
    int any;
    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %d", &number) != 1)
        {
            _eh_exit(eINPUT_invalid_eno, eINPUT_invalid)
        }
        else if (number == 0)
        {
            break;
        }
        else
        {
            any = 0;
            if (number % 2 == 0)
            {
                fprintf(file_2, "%d\n", number);
                ++any;
            }
            if (number % 3 == 0)
            {
                fprintf(file_3, "%d\n", number);
                ++any;
            }
            if (number % 5 == 0)
            {
                fprintf(file_5, "%d\n", number);
                ++any;
            }
            if (!any)
            {
                fprintf(file_0, "%d\n", number);
            }
        }
    }

    print_ln("Files saved");
    _h_exit()
}
