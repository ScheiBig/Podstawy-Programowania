#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__string_endswith()
__include__discard_stdin()
#include "matrix_utils.h"


int main()
{
    char* filename = (char*)malloc(sizeof(char) * 20);
    if (filename == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter first file path:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%19s", filename);
    discard_stdin();
    int err_code;
    struct matrix_t* (*getter)(c_cstring, int*);
    if (string_endswith(filename, ".bin"))
    {
        getter = matrix_load_b;
    }
    else if (string_endswith(filename, ".txt"))
    {
        getter = matrix_load_t;
    }
    else
    {
        free(filename);
        __m_exit(eFILE_unsupported);
    }
    struct matrix_t* mat_1;
    if ((mat_1 = getter(filename, &err_code)) == null)
    {
        switch (err_code)
        {
        case 2:
            free(filename);
            __m_exit(eFILE_noaccess);
        case 3:
            free(filename);
            __m_exit(eFILE_corrupted);
        case 4:
            free(filename);
            __m_exit(eMEMORY_cantallocate);
        default:
            break;
        }
    }
    print_ln("Enter second file path:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%19s", filename);
    if (string_endswith(filename, ".bin"))
    {
        getter = matrix_load_b;
    }
    else if (string_endswith(filename, ".txt"))
    {
        getter = matrix_load_t;
    }
    else
    {
        free(filename);
        matrix_destroy_struct(&mat_1);
        __m_exit(eFILE_unsupported);
    }
    struct matrix_t* mat_2;
    if ((mat_2 = getter(filename, &err_code)) == null)
    {
        switch (err_code)
        {
        case 2:
            free(filename);
            matrix_destroy_struct(&mat_1);
            __m_exit(eFILE_noaccess);
        case 3:
            free(filename);
            matrix_destroy_struct(&mat_1);
            __m_exit(eFILE_corrupted);
        case 4:
            free(filename);
            matrix_destroy_struct(&mat_1);
            __m_exit(eMEMORY_cantallocate);
        default:
            break;
        }
    }

    struct matrix_t* mat_add = matrix_add(mat_1, mat_2);
    struct matrix_t* mat_sub = matrix_subtract(mat_1, mat_2);
    struct matrix_t* mat_mul = matrix_multiply(mat_1, mat_2);

    if (mat_add == null)
    {
        print_ln("Error");
    }
    else
    {
        matrix_display(mat_add);
    }

    if (mat_sub == null)
    {
        print_ln("Error");
    }
    else
    {
        matrix_display(mat_sub);
    }
    
    if (mat_mul == null)
    {
        print_ln("Error");
    }
    else
    {
        matrix_display(mat_mul);
    }

    free(filename);
    matrix_destroy_struct(&mat_1);
    matrix_destroy_struct(&mat_2);
    matrix_destroy_struct(&mat_add);
    matrix_destroy_struct(&mat_sub);
    matrix_destroy_struct(&mat_mul);

    return 0;
}
