#ifndef PODSTAWY_PROGRAMOWANIA_1_MY_UTILS_H
#define PODSTAWY_PROGRAMOWANIA_1_MY_UTILS_H

// (C) Marcin Jeznach (TM), plz no steal

#include <stdio.h>
#define eprint_ln(msg) fprintf(stderr, msg "\n" )
#define _e_exit(eno, msg) { eprint_ln(msg); return eno; }
#define printf_ln(format, ...) printf(format "\n", __VA_ARGS__)
#define print_ln(format) printf(format "\n")
#define print_n() printf("\n")

#define sign(num) ((num >> sizeof(num) * 8 - 1) & 0x1)
#define clip_range(in, from, to) ((in % to - from + 1) + from)
#define is_even(num) (num % 2 == 0)
#define is_odd(num) (num % 2 != 0)

#define arr_size(arr) (sizeof(arr) / sizeof(arr[0]))

#define is_letter(chr) ('a' <= chr && chr <= 'z' || 'A' <= chr && chr <= 'Z')
#define is_uppercase(chr) ('A' <= chr && chr <= 'Z')
#define is_lowercase(chr) ('a' <= chr && chr <= 'z')
#define is_digit(chr) ('0' <= chr && chr <= '9')
#define ctoi(chr) (chr - '0')

#define cond_assign_l(to, arg) (to = to < arg ? arg : to)
#define cond_assign_le(to, arg) (to = to <= arg ? arg : to)
#define cond_assign_g(to, arg) (to = to > arg ? arg : to)
#define cond_assign_ge(to, arg) (to = to >= arg ? arg : to)
#define double_almost_eq(arg, to, eps) ((to - eps) < arg && arg < (to + eps))

#define REGISTER_SWAP(type) \
    void swap_int(type* a1, type* a2)\
    {\
        type temp = *a1;\
        *a1 = *a2;\
        *a2 = temp;\
    }\

#endif //PODSTAWY_PROGRAMOWANIA_1_MY_UTILS_H
