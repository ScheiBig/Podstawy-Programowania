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
#include "data_type.h"

void* connect(data_type_e data_type, int el_num, ...);

int is_term(byte* term, byte* el, size_t el_size);

size_t count_elements(byte* term, size_t el_size, size_t el_num, va_list args);
void* concat_elements(byte* term, size_t el_size, size_t el_num, va_list args, void* dest);

void destroy_array(void** arr, size_t el_size, size_t el_num);

const short s_t = -1;
const int i_t = -1;
const float f_t = -1;
const double d_t = -1;
const long l_t = -1;

#define a1     *(arrays + 0)
#define a2 a1, *(arrays + 1)
#define a3 a2, *(arrays + 2)
#define a4 a3, *(arrays + 3)

#define _case(num) \
    case num:  \
        result = connect(data_type, el_num, a ## num); break;


int main()
{
    data_type_e data_type;
    int temp;
    print_ln("Select data type:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &temp) != 1) { __m_exit(eINPUT_invalid); }
    else if ((!is_num_in_range(temp, 0, 4))) { __m_exit(eDATA_invalid); }
    data_type = (data_type_e)temp;
    size_t el_size;
    c_cstring form;
    byte* term;
    switch (data_type)
    {
    case data_type_short:
        el_size = sizeof(short);    // 2ul
        term = (byte*)&s_t;
        form = " %hd";
        break;
    case data_type_int:
        el_size = sizeof(int);      // 4ul
        term = (byte*)&i_t;
        form = " %d";
        break;
    case data_type_float:
        el_size = sizeof(float);    // 4ul
        term = (byte*)&f_t;
        form = " %f";
        break;
    case data_type_double:
        el_size = sizeof(double);   // 8ul
        term = (byte*)&d_t;
        form = " %lf";
        break;
    case data_type_long:
        el_size = sizeof(long);     // 8ul
        term = (byte*)&l_t;
        form = " %ld";
        break;
    }

    size_t el_num;
    print_ln("Enter number of arrays:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &temp) != 1) { __m_exit(eINPUT_invalid); }
    else if ((!is_num_in_range(temp, 2, 4))) { __m_exit(eDATA_invalid); }
    el_num = (size_t)temp;

    void** arrays = (void**)calloc(el_num, sizeof(void*));
    if (arrays == null) { __m_exit(eMEMORY_cantallocate); }

    for (size_t i = 0; i < el_num; ++i)
    {
        size_t num;
        print_ln("Enter number of elements:");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &temp) != 1)
        {
            destroy_array(arrays, el_size, el_num);
            __m_exit(eINPUT_invalid);
        }
        else if (temp <= 0)
        {
            destroy_array(arrays, el_size, el_num);
            __m_exit(eDATA_invalid);
        }
        num = (size_t)temp;
        if ((*(arrays + i) = (byte*)calloc(num + 1, el_size)) == null)
        {
            destroy_array(arrays, el_size, el_num);
            __m_exit(eMEMORY_cantallocate);
        }

        print_ln("Enter numbers:");
        byte* el;
        for (el = (byte*)*(arrays + i); el < ((byte*)*(arrays + i) + num * el_size); el += el_size)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf(form, (void*)el) != 1)
            {
                destroy_array(arrays, el_size, el_num);
                __m_exit(eINPUT_invalid);
            }
        }
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        memcpy(el, term, el_size);
    }

    void* result;

    switch (el_num)
    {
        _case(1) _case(2) _case(3) _case(4)
    }

    if (result == null)
    {
        destroy_array(arrays, el_size, el_num);
        __m_exit(eMEMORY_cantallocate);
    }

    for (byte* r = (byte*)result; !is_term(term, r, el_size); r += el_size)
    {
        switch (data_type)
        {
        case data_type_short:
            printf(form, *(short*)r);
            break;
        case data_type_int:
            printf(form, *(int*)r);
            break;
        case data_type_float:
            printf(form, *(float*)r);
            break;
        case data_type_double:
            printf(form, *(double*)r);
            break;
        case data_type_long:
            printf(form, *(long*)r);
            break;
        }
    }
    print_n();

    free(result);
    destroy_array(arrays, el_size, el_num);
    return 0;
}

void* connect(data_type_e data_type, int el_num, ...)
{
    if (el_num <= 0) { return null; }
    size_t el_size;
    byte* term;
    switch (data_type)
    {
    case data_type_short:
        el_size = sizeof(short);    // 2ul
        term = (byte*)&s_t;
        break;
    case data_type_int:
        el_size = sizeof(int);      // 4ul
        term = (byte*)&i_t;
        break;
    case data_type_float:
        el_size = sizeof(float);    // 4ul
        term = (byte*)&f_t;
        break;
    case data_type_double:
        el_size = sizeof(double);   // 8ul
        term = (byte*)&d_t;
        break;
    case data_type_long:
        el_size = sizeof(long);     // 8ul
        term = (byte*)&l_t;
        break;
    default: return null;
    }
    va_list args;
    va_start(args, el_num);
    size_t el_count = count_elements(term, el_size, el_num, args);
    va_end(args);
    if (el_count == 0) { return null; }
    void* dest = calloc(el_count + 1, el_size);
    if (dest == null) { return null; }
    va_start(args, el_num);
    concat_elements(term, el_size, el_num, args, dest);
    va_end(args);
    return dest;
}

size_t count_elements(byte* term, size_t el_size, size_t el_num, va_list args)
{
    size_t cnt = 0;
    void* cur_arr;
    for (size_t i = 0; i < el_num; ++i)
    {
        cur_arr = va_arg(args, void*);
        for (byte* e = (byte*)cur_arr; !is_term(term, e, el_size);
            e += el_size,
            ++cnt);
    }
    return cnt;
}

void* concat_elements(byte* term, size_t el_size, size_t el_num, va_list args, void* dest)
{
    size_t cnt = 0;
    void* cur_arr;
    byte* d = (byte*)dest;
    for (size_t i = 0; i < el_num; ++i)
    {
        cur_arr = va_arg(args, void*);
        for (byte* e = (byte*)cur_arr; !is_term(term, e, el_size);
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            memcpy(d + el_size * (cnt++), e, el_size),
            e += el_size);
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memcpy(d + el_size * cnt, term, el_size);
    return dest;
}

int is_term(byte* term, byte* el, size_t el_size) { return !memcmp(term, el, el_size); }

void destroy_array(void** arr, size_t el_size, size_t el_num)
{
    void** e = arr;
    while (*e != null && e < arr + el_num)
    {
        free(*e);
        ++e;
    }
    free(arr);
}
