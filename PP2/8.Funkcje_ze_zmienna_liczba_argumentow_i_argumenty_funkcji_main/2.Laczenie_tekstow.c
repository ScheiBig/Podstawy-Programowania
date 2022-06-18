#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>

#include "my_utils_v3.h"

int concatenate(cstring buf, int buf_len, int el_num, ...);

int count_chars(int el_num, va_list args);
void destroy_array(cstring* arr, size_t el_num);

void discard_stdin() { while (fgetc(stdin) != '\n'); }

#define a1     *(arrays + 0)
#define a2 a1, *(arrays + 1)
#define a3 a2, *(arrays + 2)
#define a4 a3, *(arrays + 3)

#define _case(num) \
    case num:  \
        concatenate(result, 1001 * 4, el_num, a ## num); break;


int main()

{
    cstring* arrays = (cstring*)calloc(4, sizeof(cstring));
    if (arrays == null) { __m_exit(eMEMORY_cantallocate); }

    for (size_t i = 0; i < 4; ++i)
    {
        if ((*(arrays + i) = (cstring)calloc(1001, sizeof(char))) == null)
        {
            destroy_array(arrays, 4);
            __m_exit(eMEMORY_cantallocate);
        }
    }

    cstring result = (cstring)calloc(1001 * 4, sizeof(char));
    if (result == null)
    {
        destroy_array(arrays, 4);
        __m_exit(eMEMORY_cantallocate);
    } 
    int temp;
    size_t el_num;
    print_ln("Enter number of strings:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &temp) != 1)
    {
        destroy_array(arrays, 4);
        free(result);
        __m_exit(eINPUT_invalid);
    }
    else if ((!is_num_in_range(temp, 2, 4)))
    {
        destroy_array(arrays, 4);
        free(result);
        __m_exit(eDATA_invalid);
    }
    el_num = (size_t)temp;

    discard_stdin();

    print_ln("Enter strings:");
    for (size_t i = 0; i < el_num; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        fgets(*(arrays + i), 1001, stdin);
        size_t last = strlen(*(arrays + i)) - 1;
        if (*(*(arrays + i) + last) == '\n') { *(*(arrays + i) + last) = str_term; }
        else { discard_stdin(); }
    }
    
    switch (el_num)
    {
        _case(1) _case(2) _case(3) _case(4)
    }

    printf("%s", result);

    destroy_array(arrays, 4);
    free(result);
    return 0;
}


int concatenate(cstring buf, int buf_len, int el_num, ...)
{
    if (buf == null || buf_len <= 0 || el_num <= 0) { return 1; }
    
    va_list args;
    va_start(args, el_num);
    if (buf_len < count_chars(el_num, args) + el_num)
    {
        va_end(args);
        return 2;
    }
    va_start(args, el_num);
    *buf = str_term;
    for (int i = 0; i < el_num - 1;
        ++i,
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
        strcat(buf, va_arg(args, cstring)),
        strcat(buf, " "));
    strcat(buf, va_arg(args, cstring));
    va_end(args);
    return 0;
}

int count_chars(int el_num, va_list args)
{
    int cnt = 0;
    for (int i = 0; i < el_num;
        ++i,
        cnt += strlen(va_arg(args, cstring)));
    return cnt;
}

void destroy_array(cstring* arr, size_t el_num)
{
    cstring* e = arr;
    while (*e != null && e < arr + el_num)
    {
        free(*e);
        ++e;
    }
    free(arr);
}
