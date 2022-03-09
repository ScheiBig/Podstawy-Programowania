#pragma once

// (C) Marcin Jeznach (TM), plz no steal

#define eFILE_cantcreate 5
#define eFILE_cantcreate_msg "Couldn't create file"
#define eFILE_noaccess 4
#define eFILE_noaccess_msg "Couldn't open file"
#define eDATA_none 3
#define eDATA_none_msg "Not enough data available"
#define eDATA_invalid 2
#define eDATA_invalid_msg "Incorrect input data"
#define eINPUT_invalid 1
#define eINPUT_invalid_msg "Incorrect input"

#include <stdio.h>
#define eprint_ln(msg) fprintf(stderr, msg "\n" )
#define printf_ln(format, ...) printf(format "\n", __VA_ARGS__)
#define print_ln(format) printf(format "\n")
#define print_n() printf("\n")
#define _el_exit(eno, msg) { eprint_ln(msg); return eno; }
#define _ml_exit(eno, msg) { print_ln(msg); return eno; }
#define _e_exit(eno, msg) { fprint(msg, stderr); return eno; }
#define _m_exit(eno, msg) { printf(msg); return eno; }

#define sign(num) ((num >> sizeof(num) * 8 - 1) & 0x1)
#define clip_range(in, from, to) ((in % to - from + 1) + from)
#define is_even(num) (num % 2 == 0)
#define is_odd(num) (num % 2 != 0)

// #define arr_size(arr) (sizeof(arr) / sizeof(arr[0]))

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
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

#define REGISTER_SWAP(type) \
    void swap_##type(type* a1, type* a2)\
    {\
        type temp = *a1;\
        *a1 = *a2;\
        *a2 = temp;\
    }

#ifdef __discard_stdin__
/**
 * @brief Clears `stdin` until newline character is met.
 * 
 * @return Number of characters left in `stdin` prior to this call. 
 */
int discard_stdin()
{
    int count = 0;
    while (fgetc(stdin) != '\n') ++count;
    return count;
}
#endif