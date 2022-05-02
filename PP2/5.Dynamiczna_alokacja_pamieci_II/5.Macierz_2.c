#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__string_endswith()
#include "matrix_utils.h"


int main()
{

    int w, h;
    print_ln("Enter matrix dimensions:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d %d", &w, &h) != 2)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (w <= 0 || h <= 0)
    {
        __m_exit(eDATA_invalid);
    }

    struct matrix_t* mat;

    if ((mat = matrix_create_struct(w, h)) == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    if (matrix_read(mat) != 0)
    {
        matrix_destroy_struct(&mat);
        __m_exit(eINPUT_invalid);
    }
    char* filename = (char*)malloc(sizeof(char) * 40);
    if (filename == null)
    {
        matrix_destroy_struct(&mat);
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter file path:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%39s", filename);

    struct matrix_t* trans_mat;
    if ((trans_mat = matrix_transpose(mat)) == null)
    {
        matrix_destroy_struct(&mat);
        free(filename);
        __m_exit(eMEMORY_cantallocate);
    }
        
    if (string_endswith(filename, ".bin"))
    {
        if (matrix_save_b(trans_mat, filename) != 0)
        {
            matrix_destroy_struct(&mat);
            matrix_destroy_struct(&trans_mat);
            free(filename);
            __m_exit(eFILE_cantcreate);
        }
    }
    else if (string_endswith(filename, ".txt"))
    {
        if (matrix_save_t(trans_mat, filename) != 0)
        {
            matrix_destroy_struct(&mat);
            matrix_destroy_struct(&trans_mat);
            free(filename);
            __m_exit(eFILE_cantcreate);
        }
    }
    else
    {
        matrix_destroy_struct(&mat);
        matrix_destroy_struct(&trans_mat);
        free(filename);
        __m_exit(eFILE_unsupported);
    }

    matrix_destroy_struct(&mat);
    matrix_destroy_struct(&trans_mat);
    free(filename);
    print_ln("File saved");
    return 0;
}
