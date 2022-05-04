#ifndef PODSTAWY_PROGRAMOWANIA_1_MATRIX_H
#define PODSTAWY_PROGRAMOWANIA_1_MATRIX_H

// (C) Marcin Jeznach (TM), plz no steal

#include <stdio.h>

#ifdef __MATRIX_ADD__
#define _REGISTER_INT_MATRIX_ADD(size) \
    void matrix_add_##size(int m1[size][size], int m2[size][size], int out[size][size])\
    {\
        for (size_t r = 0; r < size; ++r)\
        {\
            for (size_t c = 0; c < size; ++c)\
            {\
                out[r][c] = m1[r][c] + m2[r][c];\
            }\
        }\
    }\

#else
#define _REGISTER_INT_MATRIX_ADD(size)  
#endif


#ifdef __MATRIX_SUB__
#define _REGISTER_INT_MATRIX_SUB(size) \
    void matrix_sub_##size(int m1[size][size], int m2[size][size], int out[size][size])\
    {\
        for (size_t r = 0; r < size; ++r)\
        {\
            for (size_t c = 0; c < size; ++c)\
            {\
                out[r][c] = m1[r][c] - m2[r][c];\
            }\
        }\
    }\

#else
#define _REGISTER_INT_MATRIX_SUB(size)  
#endif


#ifdef __MATRIX_NEG__
#define _REGISTER_INT_MATRIX_NEG(size) \
    void matrix_neg_##size(int m[size][size], int out[size][size])\
    {\
        for (size_t r = 0; r < size; ++r)\
        {\
            for (size_t c = 0; c < size; ++c)\
            {\
                out[r][c] = -m[r][c];\
            }\
        }\
    }\

#else
#define _REGISTER_INT_MATRIX_NEG(size)  
#endif


#ifdef __MATRIX_MUL__
#define _REGISTER_INT_MATRIX_MUL(size) \
    void matrix_mul_##size(int m1[size][size], int m2[size][size], int out[size][size])\
    {\
        for (int r = 0; r < size; ++r)\
        {\
            for (int c = 0; c < size; ++c)\
            {\
                out[r][c] = 0;\
                for (int i = 0; i < size; ++i)\
                {\
                    out[r][c] += m1[r][i] * m2[i][c];\
                }\
            }\
        }\
    }\

#else
#define _REGISTER_INT_MATRIX_MUL(size)  
#endif


#ifdef __MATRIX_CSUM__
#define _REGISTER_INT_MATRIX_CSUM(size) \
    void matrix_colsum_##size(int m[size][size], int out[size])\
    {\
        for (int r = 0; r < size; ++r)\
        {\
            out[r] = 0;\
            for (int c = 0; c < size; ++c)\
            {\
                out[r] += m[r][c];\
            }\
        }\
    }\

#else
#define _REGISTER_INT_MATRIX_CSUM(size)  
#endif


#ifdef __MATRIX_RSUM__
#define _REGISTER_INT_MATRIX_RSUM(size) \
    void matrix_rowsum_##size(int m[size][size], int out[size])\
    {\
        for (int c = 0; c < size; ++c)\
        {\
            out[c] = 0;\
            for (int r = 0; r < size; ++r)\
            {\
                out[c] += m[r][c];\
            }\
        }\
    }\

#else
#define _REGISTER_INT_MATRIX_RSUM(size)  
#endif


#ifdef __MATRIX_PRINT__
#define _REGISTER_INT_MATRIX_PRINT(size) \
    void matrix_print_##size(int m[size][size], int width)\
    {\
        for (size_t r = 0; r < size; ++r)\
        {\
            for (size_t c = 0; c < size; ++c)\
            {\
                printf("%*d ", width, m[r][c]);\
            }\
            printf("\n");\
        }\
        printf("\n");\
    }\

#else
#define _REGISTER_INT_MATRIX_PRINT(size)  
#endif


#ifdef __VECTOR_PRINT__
#define _REGISTER_INT_VECTOR_PRINT(size) \
    void vector_print_##size(int v[size], int width)\
    {\
        for (size_t r = 0; r < size; ++r)\
        {\
            printf("%*d ", width, v[r]);\
        }\
        printf("\n");\
    }\

#else
#define _REGISTER_INT_VECTOR_PRINT(size)  
#endif

#define REGISTER_INT_MATRIX(size) \
    _REGISTER_INT_MATRIX_ADD(size) \
    _REGISTER_INT_MATRIX_SUB(size) \
    _REGISTER_INT_MATRIX_NEG(size) \
    _REGISTER_INT_MATRIX_MUL(size) \
    _REGISTER_INT_MATRIX_CSUM(size) \
    _REGISTER_INT_MATRIX_RSUM(size) \
    _REGISTER_INT_MATRIX_PRINT(size) \
    _REGISTER_INT_VECTOR_PRINT(size)

#endif //PODSTAWY_PROGRAMOWANIA_1_MATRIX_H
