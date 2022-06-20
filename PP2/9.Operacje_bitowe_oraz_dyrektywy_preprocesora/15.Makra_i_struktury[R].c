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
#include "functions.h"

enum type_t
{
    _int, _double
};

DEFINE_ARRAY(int)
CREATE_ARRAY(int)
FREE_ARRAY(int)
SAVE_ARRAY(int)
LOAD_ARRAY(int)
SORT_ARRAY(int)

DEFINE_ARRAY(double)
CREATE_ARRAY(double)
FREE_ARRAY(double)
SAVE_ARRAY(double)
LOAD_ARRAY(double)
SORT_ARRAY(double)


int main()
{
    cstring filename = (cstring)calloc(31, sizeof(char));
    if (filename == null) { __m_exit(eMEMORY_cantallocate); }
    print_ln("Enter a file name: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%30[^\n]s", filename);
    while (getc(stdin) != '\n');

    int type;
    print_ln("Select data type:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &type) != 1)
    {
        free(filename);
        __m_exit(eINPUT_invalid);
    }
    else if (!is_num_in_range(type, 0, 1))
    {
        free(filename);
        __m_exit(eDATA_invalid);
    }

    switch (type)
    {
    case _int: {
        array_int_s* array;
        switch (load_array_int(&array, (c_cstring)filename))
        {
        case 1:
            free(filename);
            __m_exit(eINPUT_invalid);
        case 2:
            free(filename);
            __m_exit(eFILE_noaccess);
        case 3:
            free(filename);
            __m_exit(eFILE_corrupted);
        case 4:
            free(filename);
            __m_exit(eMEMORY_cantallocate);
        }
        sort_array_int(array);
        switch (save_array_int(array, (c_cstring)filename))
        {
        case 1:
            free(filename);
            free_array_int(array);
            __m_exit(eINPUT_invalid);
        case 2:
            free(filename);
            free_array_int(array);
            __m_exit(eFILE_cantcreate);
        default:
            free(filename);
            free_array_int(array);
            __m_exit(iFILE_saved);
        }
    }
    case _double: {
        array_double_s* array;
        switch (load_array_double(&array, (c_cstring)filename))
        {
        case 1:
            free(filename);
            __m_exit(eINPUT_invalid);
        case 2:
            free(filename);
            __m_exit(eFILE_noaccess);
        case 3:
            free(filename);
            __m_exit(eFILE_corrupted);
        case 4:
            free(filename);
            __m_exit(eMEMORY_cantallocate);
        }
        sort_array_double(array);
        switch (save_array_double(array, (c_cstring)filename))
        {
        case 1:
            free(filename);
            free_array_double(array);
            __m_exit(eINPUT_invalid);
        case 2:
            free(filename);
            free_array_double(array);
            __m_exit(eFILE_cantcreate);
        default:
            free(filename);
            free_array_double(array);
            __m_exit(iFILE_saved);
        }
    }
    }

    
    return 0;
}
