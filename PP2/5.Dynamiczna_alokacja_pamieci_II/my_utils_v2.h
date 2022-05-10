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
#define cond_assign_nn(to, arg) { if (to != NULL) *to = arg; }
#define double_almost_eq(arg, to, eps) ((to - eps) < arg && arg < (to + eps))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define is_in_range(dest_start, dest_end, src_start, src_end, src_offset) \
    (dest_start <= (src_start + src_offset) && (src_end + src_offset) <= dest_end)

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


#define __include__discard_stdin()  \
    int discard_stdin() \
    {\
        int count = 0;\
        while (fgetc(stdin) != '\n') ++count;\
        return count;\
    } 

#define __include__discard_stream()  \
    int discard_stream(p_file stream) \
    {\
        int count = 0;\
        while (fgetc(stream) != '\n') ++count;\
        return count;\
    } 


#define __include__string_prepend() \
    cstring string_prepend(cstring string, char prefix)\
    {\
        int len = strlen(string) + 1;\
        for (int i = len; i >= 1; --i)\
        {\
            *(string + i) = *(string + i - 1);\
        }\
        *(string) = prefix;\
        return string;\
    }

#define __include__string_endswith() \
    int string_endswith(c_cstring str, c_cstring end)\
    {\
        if (str == NULL || end == NULL)\
        {\
            return -1;\
        }\
        size_t str_l = strlen(str);\
        size_t end_l = strlen(end);\
        if (str_l < end_l)\
        {\
            return -1;\
        }\
        int ret = 1;\
        c_cstring s = str + str_l - end_l;\
        \
        for (size_t e = 0; e < end_l; ++e)\
        {\
            ret *= (*(s + e) == *(end + e));\
        }\
        if (ret) return 1;\
        \
        return 0;\
    }

#define __include__string_split() \
    typedef struct \
    { \
        c_cstring start_ptr; \
        size_t length; \
        c_cstring delimiters; \
    } token; \
\
    token string_split(c_cstring str, c_cstring delimiters) \
    { \
        if (str == null || strlen(str) == 0 || delimiters == null || strlen(delimiters) == 0) \
        { \
            return (token) { .start_ptr = null, .length = 0, .delimiters = null }; \
        } \
        c_cstring cur_match = str; \
        c_cstring next_match = strpbrk(cur_match, delimiters); \
        size_t len = strlen(cur_match); \
        while (true) \
        { \
            if (next_match == null) \
            { \
                return (token) { .start_ptr = str, .length = len, .delimiters = null }; \
            } \
            if (next_match - cur_match == 0) \
            { \
                next_match = strpbrk(++cur_match, delimiters); \
                continue; \
            } \
            return (token) { .start_ptr = cur_match, .length = (size_t)(next_match - cur_match), .delimiters = delimiters }; \
        } \
    } \
\
    token string_split_next(token prev) \
    { \
        if (prev.start_ptr == null || prev.delimiters == null || prev.length == 0) \
        { \
            return (token) { .start_ptr = null, .length = 0, .delimiters = null }; \
        } \
        return string_split(prev.start_ptr + prev.length + 1, prev.delimiters); \
    } \
\
    size_t string_split_count(c_cstring str, c_cstring delimiters) \
    { \
        if (str == null || strlen(str) == 0 || delimiters == null || strlen(delimiters) == 0) \
        { \
            return 0; \
        } \
        size_t count = 0; \
        for ( \
            token tok = string_split(str, delimiters); \
            tok.start_ptr != null; \
            tok = string_split_next(tok) \
            ) \
        { \
            ++count; \
        } \
        return count; \
    }
