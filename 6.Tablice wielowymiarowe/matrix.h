#ifndef PODSTAWY_PROGRAMOWANIA_1_MATRIX_H
#define PODSTAWY_PROGRAMOWANIA_1_MATRIX_H

#include <stdio.h>

#define REGISTER_INT_MATRIX(size) \
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
\
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
\
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
\
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

#endif //PODSTAWY_PROGRAMOWANIA_1_MATRIX_H
