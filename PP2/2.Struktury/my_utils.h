/**
 * @file my_utils.h
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Various utilities:
 *            - predefined code errors and messages,
 *            - macros for printing to stdout and stderr with newline-termination
 *            - macros for returning from functions with printing messages
 *            - number manipulation
 *            - ASCII manipulation
 *            - conditional operations
 *            - various stream/pointer manipulations
 */
#pragma once

#define eFILE_unsupported 7
#define eFILE_unsupported_msg "Unsupported file format"
#define eFILE_corrupted 6
#define eFILE_corrupted_msg "File corrupted"
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
#define _e_exit(eno, msg) { fprintf(stderr, msg); return eno; }
#define _m_exit(eno, msg) { printf(msg); return eno; }

#define sign(num) ((num >> sizeof(num) * 8 - 1) & 0x1)
#define clip_range(in, from, to) (in % (to - from + 1) + from)
#define is_even(num) (num % 2 == 0)
#define is_odd(num) (num % 2 != 0)

 // #define arr_size(arr) (sizeof(arr) / sizeof(arr[0]))

#define is_letter(chr) ('a' <= chr && chr <= 'z' || 'A' <= chr && chr <= 'Z')
#define is_uppercase(chr) ('A' <= chr && chr <= 'Z')
#define is_lowercase(chr) ('a' <= chr && chr <= 'z')
#define to_uppercase(chr) (is_lowercase(chr) ? (chr - 'a' + 'A') : chr)
#define to_lowercase(chr) (is_uppercase(chr) ? (chr - 'A' + 'a') : chr)
#define is_vovel(chr) (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u' || chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U')
#define is_digit(chr) ('0' <= chr && chr <= '9')
#define ctoi(chr) (chr - '0')
#define str_term (char)0

#define cond_assign_l(to, arg) (to = to < arg ? arg : to)
#define cond_assign_le(to, arg) (to = to <= arg ? arg : to)
#define cond_assign_g(to, arg) (to = to > arg ? arg : to)
#define cond_assign_ge(to, arg) (to = to >= arg ? arg : to)
#define cond_assign_nn(to, arg) { if (to != NULL) *to = arg; }
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

#ifdef __string_prepend__
#include <string.h>
/**
 * @brief Inserts character in front of string
 *
 * @return Pointer to passed string (modified)
 */
char* string_prepend(char* string, char prefix)
{
    int len = strlen(string) + 1;
    for (int i = len; i >= 1; --i)
    {
        *(string + i) = *(string + i - 1);
    }
    *(string) = prefix;
    return string;
}
#endif
