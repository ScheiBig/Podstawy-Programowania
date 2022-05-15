/**
 * @file my_utils_v2.h
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Various utilities:
 *            - predefined code errors and messages,
 *            - macros for printing to stdout and stderr with newline-termination
 *            - macros for returning from functions with printing messages
 *            - number manipulation
 *            - ASCII manipulation
 *            - conditional operations
 *            - various stream/pointer manipulations
 *
 * Version v2 indicates back-not-compatible changes to *_exit macros and removes
 * ifdef-guards, as Dante still recognizes them as unused functions
 *
 * Version v3 splits functions created by macros to separate files
 */
#pragma once

#define eMEMORY_cantallocate_eno 8
#define eMEMORY_cantallocate "Failed to allocate memory"
#define eFILE_unsupported_eno 7
#define eFILE_unsupported "Unsupported file format"
#define eFILE_corrupted_eno 6
#define eFILE_corrupted "File corrupted"
#define eFILE_cantcreate_eno 5
#define eFILE_cantcreate "Couldn't create file"
#define eFILE_noaccess_eno 4
#define eFILE_noaccess "Couldn't open file"
#define eDATA_insufficient_eno 3
#define eDATA_insufficient "Not enough data available"
#define eDATA_invalid_eno 2
#define eDATA_invalid "Incorrect input data"
#define eINPUT_invalid_eno 1
#define eINPUT_invalid "Incorrect input"


#include <stdio.h>
#define eprint_ln(msg) fprintf(stderr, msg "\n")
#define eprintf_ln(msg, ...) fprintf(stderr, msg "\n", __VA_ARGS__)
#define eprintf(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#define eprint_n() fprintf(stderr, "\n")
#define print_ln(format) printf(format "\n")
#define printf_ln(format, ...) printf(format "\n", __VA_ARGS__)
#define print_n() printf("\n")

#define _el_exit(eno, msg) return eno * !!eprint_ln(msg)
#define _ml_exit(eno, msg) return eno * !!print_ln(msg)
#define _e_exit(eno, msg) return eno * !!fprintf(stderr, msg)
#define _m_exit(eno, msg) return eno * !!printf(msg)
#define __el_exit(msg) return msg ## _eno * !!eprint_ln(msg)
#define __ml_exit(msg) return msg ## _eno * !!print_ln(msg)
#define __e_exit(msg) return msg ## _eno * !!fprintf(stderr, msg)
#define __m_exit(msg) return msg ## _eno * !!printf(msg)


#define clip_range(in, from, to) (in % (to - from + 1) + from)
#define is_even(num) (num % 2 == 0)
#define is_odd(num) (num % 2 != 0)

#define is_letter(chr) ('a' <= chr && chr <= 'z' || 'A' <= chr && chr <= 'Z')
#define is_uppercase(chr) ('A' <= chr && chr <= 'Z')
#define is_lowercase(chr) ('a' <= chr && chr <= 'z')
#define to_uppercase(chr) (is_lowercase(chr) ? (chr - 'a' + 'A') : chr)
#define to_lowercase(chr) (is_uppercase(chr) ? (chr - 'A' + 'a') : chr)
#define is_vovel(chr) (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u' \
    || chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U')
#define is_digit(chr) ('0' <= chr && chr <= '9')
#define ctoi(chr) (chr - '0')
#define str_term (char)0

#define cond_assign_l(to, arg) (to = to < arg ? arg : to)
#define cond_assign_le(to, arg) (to = to <= arg ? arg : to)
#define cond_assign_g(to, arg) (to = to > arg ? arg : to)
#define cond_assign_ge(to, arg) (to = to >= arg ? arg : to)
#define cond_assign_nn(to, arg) do { if (to != NULL) *to = arg; } while(0)
#define double_almost_eq(arg, to, eps) ((to - eps) < arg && arg < (to + eps))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define is_in_range(dest_start, dest_end, src_start, src_end, src_offset) \
    (dest_start <= (src_start + src_offset) && (src_end + src_offset) <= dest_end)

#define to_string(arg) #arg

#define null NULL
typedef FILE* p_file;
typedef char* cstring;
typedef const char* c_cstring;
#define TO_DO __attribute__( warning("Function is not implemented") )

#define __include__swap(type) \
    void swap_##type(type* a1, type* a2)\
    {\
        type temp = *a1;\
        *a1 = *a2;\
        *a2 = temp;\
    }

#define ASCIIset_letterslow "abcdefghijklmnopqrstuvwxyz"
#define ASCIIet_lettersupp "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ASCIIset_numbers "0123456789"
#define ASCIIset_symbols "\n\t !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
