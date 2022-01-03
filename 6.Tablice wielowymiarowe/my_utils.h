#ifndef PODSTAWY_PROGRAMOWANIA_1_MY_UTILS_H
#define PODSTAWY_PROGRAMOWANIA_1_MY_UTILS_H

// (C) Marcin Jeznach (TM), plz no steal

#include <stdio.h>
#define eprintf(msg) fprintf(stderr, msg)
#define _e_exit(eno, msg) { eprintf(msg); return eno; }

#define SIGN(num) ((num >> sizeof(num) * 8 - 1) & 0x1)
#define CLIP_RANGE(in, from, to) ((in % to - from + 1) + from)

#define A_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define IS_LETTER(chr) ('a' <= chr && chr <= 'z' || 'A' <= chr && chr <= 'Z')
#define IS_UPPERCASE(chr) ('A' <= chr && chr <= 'Z')
#define IS_LOWERCASE(chr) ('a' <= chr && chr <= 'z')
#define IS_NUMBER(chr) ('0' <= chr && chr <= '9')

#define COND_ASSIGN_L(to, arg) (to = to < arg ? arg : to)
#define COND_ASSIGN_LE(to, arg) (to = to <= arg ? arg : to)
#define COND_ASSIGN_G(to, arg) (to = to > arg ? arg : to)
#define COND_ASSIGN_GE(to, arg) (to = to >= arg ? arg : to)

#define REGISTER_SWAP(type) \
    void swap_int(type* a1, type* a2)\
    {\
        type temp = *a1;\
        *a1 = *a2;\
        *a2 = temp;\
    }\

#endif //PODSTAWY_PROGRAMOWANIA_1_MY_UTILS_H
