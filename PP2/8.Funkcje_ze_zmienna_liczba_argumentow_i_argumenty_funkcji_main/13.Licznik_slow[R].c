#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>

#include "my_utils_v3.h"

int* count_words(c_cstring filename, int* err_code, int N, ...);
void find_words(p_file file, cstring word, int* results);

#define a1     *(argv + 0x2)
#define a2 a1, *(argv + 0x3)
#define a3 a2, *(argv + 0x4)
#define a4 a3, *(argv + 0x5)
#define a5 a4, *(argv + 0x6)
#define a6 a5, *(argv + 0x7)
#define a7 a6, *(argv + 0x8)
#define a8 a7, *(argv + 0x9)
#define a9 a8, *(argv + 0xa)
#define aa a9, *(argv + 0xb)
#define ab aa, *(argv + 0xc)
#define ac ab, *(argv + 0xd)
#define ad ac, *(argv + 0xe)
#define ae ad, *(argv + 0xf)

#define _case(num) \
    case 0x ## num:  \
        results = count_words(*(argv + 1), &err_code, 0x ## num, a ## num); break;


int main(int argc, char** argv)
{
    if (argc < 3) { __m_exit(eARGS_insufficient); }
    int err_code;
    int* results;
    switch (argc - 2)
    {
        _case(1) _case(2) _case(3)
        _case(4) _case(5) _case(6)
        _case(7) _case(8) _case(9)
        _case(a) _case(b) _case(c)
        _case(d) _case(e)
    default: __m_exit(eERROR_unknown);
    }
    switch (err_code)
    {
    case 1: __m_exit(eERROR_unknown);
    case 2: __m_exit(eFILE_noaccess);
    case 3: __m_exit(eMEMORY_cantallocate);
    default:
        for (int* r = results; r < results + (argc - 2); ++r) { printf_ln("%d", *r); }
    }
    free(results);

    return 0;
}

int* count_words(c_cstring filename, int* err_code, int N, ...)
{
    if (filename == null || N <= 0)
    {
        cond_assign_nn(err_code, 1);
        return null;
    }
    cond_assign_nn(err_code, 0);
    p_file file = fopen(filename, "r");
    if (file == null)
    {
        cond_assign_nn(err_code, 2);
        return null;
    }
    int* results = (int*)calloc((unsigned)N, sizeof(N));
    if (results == null)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        return null;
    }
    va_list args;
    cstring word;
    va_start(args, N);
    for (int i = 0; i < N; ++i)
    {
        *(results + i) = 0;
        word = va_arg(args, cstring);
        find_words(file, word, results + i);
    }
    fclose(file);
    va_end(args);
    return results;
}

void find_words(p_file file, cstring word, int* results)
{
    long start_pos = ftell(file);
    long f_cur;
    size_t w_len = strlen(word);
    int ch;
    int p_ch = EOF;
    *results = 0;
    bool found;

    while (true)
    {
        ch = getc(file);
        f_cur = ftell(file);
        if (ch == *word && (
            p_ch == ' ' || p_ch == '\n' ||
            p_ch == '.' || p_ch == ',' || p_ch == '\"' || p_ch == '\'' || p_ch == '-' ||
            p_ch == ':' || p_ch == ';' ||
            p_ch == 91 || p_ch == 93 || p_ch == EOF
            ))
        {
            found = true;
            for (size_t i = 1; i < w_len; ++i)
            {
                if (getc(file) != *(word + i))
                {
                    found = false;
                    break;
                }
            }
            if ((ch = getc(file)) != ' ' && ch != '\n' &&
                ch != '.' && ch != ',' && ch != '\"' && ch != '\'' && ch != '-' &&
                ch != ':' && ch != ';' &&
                ch != 91 && ch != 93 && ch != EOF)
            {
                found = false;
            }
            if (found)
            {
                ++(*results);
            }
            fseek(file, f_cur, SEEK_SET);
        }
        else if (ch == EOF)
        {
            fseek(file, start_pos, SEEK_SET);
            return;
        }
        p_ch = ch;
    }
}
