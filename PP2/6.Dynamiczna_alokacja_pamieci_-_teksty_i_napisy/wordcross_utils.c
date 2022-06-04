#include "wordcross_utils.h"

#include <stdlib.h>
#include <string.h>

#include "my_utils_v3.h"
#include "my_string.h"

// #define PAD_DEBUG true

#ifndef PAD_DEBUG
#define PAD " "
#else
#define PAD "_"
#endif

typedef struct
{
    c_cstring x_w;
    c_cstring y_w;
    size_t x_s;
    size_t y_s;
    size_t x_c;
    size_t y_c;
} word_cross;

word_cross _create_leading_word_cross(c_cstring first, c_cstring second)
{
    word_cross result = (word_cross){
        .x_w = second,
        .y_w = first,
        .x_s = strlen(second),
        .y_s = strlen(first),
        .x_c = strlen(second),
        .y_c = strlen(first)
    };
    c_cstring x_c = strpbrk(second, first);
    if (x_c == null)
    {
        return result;
    }
    c_cstring y_c;
    for (y_c = first; *y_c != *x_c; ++y_c);

    result.x_c = x_c - second;
    result.y_c = y_c - first;

    return result;
}

void _destroy(cstring** words)
{
    if (words == null || *words == null)
    {
        return;
    }
    for (cstring* word = *words; *word != null; ++word)
    {
        free(*word);
    }
    free(*words);
    *words = null;
}

int create_leading_word_cross(c_cstring first, c_cstring second, cstring** result)
{
    if (first == null || second == null || result == null ||
        strpbrk(first, ASCIIset_letterslow ASCIIset_numbers ASCIIset_symbols) != null ||
        strpbrk(second, ASCIIset_letterslow ASCIIset_numbers ASCIIset_symbols) != null)
    {
        if (result != null)
        {
            *result = null;
        }
        return -1;
    }
    if (strlen(first) == 0 || strlen(second) == 0)
    {
        *result = null;
        return -2;
    }
    word_cross cr = _create_leading_word_cross(first, second);
    if (cr.x_s == cr.x_c)
    {
        *result = null;
        return -2;
    }
    size_t y_alloc_size = cr.y_s + 1;
    if ((*result = (cstring*)calloc(y_alloc_size, sizeof(cstring))) == null)
    {
        _destroy(result);
        return -3;
    }

    //=
    // from start to cross point
    //=
    for (size_t y = 0; y < cr.y_c; ++y)
    {
        if ((*((*result) + y) = (cstring)calloc(cr.x_c + 2, sizeof(char))) == null)
        {
            _destroy(result);
            *result = null;
            return -3;
        }

        for (size_t x = 0; x < cr.x_c; ++x)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            sprintf(*((*result) + y) + x, PAD);
        }
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        sprintf(*((*result) + y) + cr.x_c, "%c", *(cr.y_w + y));
    }

    //=
    // cross point
    //=
    if ((*((*result) + cr.y_c) = (cstring)calloc(cr.x_s + 1, sizeof(char))) == null)
    {
        _destroy(result);
        return -3;
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(*((*result) + cr.y_c), "%s", cr.x_w);

    //=
    // from cross point to end
    //=
    for (size_t y = cr.y_c + 1; y < cr.y_s; ++y)
    {
        if ((*((*result) + y) = (cstring)calloc(cr.x_c + 2, sizeof(char))) == null)
        {
            _destroy(result);
            return -3;
        }

        for (size_t x = 0; x < cr.x_c; ++x)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            sprintf(*((*result) + y) + x, PAD);
        }
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        sprintf(*((*result) + y) + cr.x_c, "%c", *(cr.y_w + y));
    }
    return cr.y_c;
}

int create_double_leading_word_cross(
    c_cstring first, c_cstring second, c_cstring third, c_cstring fourth,
    cstring** result, cstring** first_cross, cstring** second_cross)
{
    if (first == null || second == null || third == null || fourth == null ||
        result == null || first_cross == null || second_cross == null ||
        strpbrk(first, ASCIIset_letterslow ASCIIset_numbers ASCIIset_symbols) != null ||
        strpbrk(second, ASCIIset_letterslow ASCIIset_numbers ASCIIset_symbols) != null ||
        strpbrk(third, ASCIIset_letterslow ASCIIset_numbers ASCIIset_symbols) != null ||
        strpbrk(fourth, ASCIIset_letterslow ASCIIset_numbers ASCIIset_symbols) != null)
    {
        cond_assign_nn(result, null);
        cond_assign_nn(first_cross, null);
        cond_assign_nn(second_cross, null);
        return 1;
    }

    if (strlen(first) == 0 || strlen(second) == 0 || strlen(third) == 0 || strlen(fourth) == 0)
    {
        *result = null;
        *first_cross = null;
        *second_cross = null;
        return 2;
    }

    //=
    // Swapping parameters, cuz no one got time to swap logic
    //=
    c_cstring t = first;
    first = second;
    second = t;
    t = third;
    third = fourth;
    fourth = t;

    word_cross cr12 = _create_leading_word_cross(first, second);
    word_cross cr34 = _create_leading_word_cross(third, fourth);
    if (cr12.x_s == cr12.x_c || cr34.x_s == cr34.x_c)
    {
        *result = null;
        *first_cross = null;
        *second_cross = null;
        return 2;
    }
    if (create_leading_word_cross(first, second, first_cross) == -3)
    {
        *result = null;
        *first_cross = null;
        *second_cross = null;
        return 3;
    }
    if (create_leading_word_cross(third, fourth, second_cross) == -3)
    {
        *result = null;
        _destroy(first_cross);
        *second_cross = null;
        return 3;
    }
    cstring* double_cross = null;
    cstring* temp_r;
    cstring temp;
    if (create_leading_word_cross(first, second, &double_cross) == -3)
    {
        *result = null;
        _destroy(first_cross);
        _destroy(second_cross);
        return 3;
    }

    //=
    // Realoc rows to contain second cross
    //=
    size_t start_i;
    size_t end_ie;
    if (cr12.y_c < cr34.y_c)
    {
        size_t diff = cr34.y_c - cr12.y_c;
        if ((temp_r = alloc_string_page_prepend(double_cross, diff)) == null)
        {
            *result = null;
            _destroy(first_cross);
            _destroy(second_cross);
            _destroy(&double_cross);
            return 3;
        }
        else
        {
            double_cross = temp_r;
        }
        start_i = 0;
    }
    else
    {
        start_i = cr12.y_c - cr34.y_c;
    }
    if ((cr12.y_s - cr12.y_c) < (cr34.y_s - cr34.y_c))
    {
        size_t diff = (cr34.y_s - cr34.y_c) - (cr12.y_s - cr12.y_c);
        if ((temp_r = alloc_string_page_append(double_cross, diff)) == null)
        {
            *result = null;
            _destroy(first_cross);
            _destroy(second_cross);
            _destroy(&double_cross);
            return 3;
        }
        else
        {
            double_cross = temp_r;
        }
        end_ie = pagelen(double_cross);
    }
    else
    {
        end_ie = pagelen(double_cross) - ((cr12.y_s - cr12.y_c) - (cr34.y_s - cr34.y_c));
    }

    //=
    // Pad everything before second cross
    //=
    for (size_t y = start_i; y < end_ie; ++y)
    {
        if ((temp = alloc_string_append(*(double_cross + y), PAD, cr12.x_s + 3 - strlen(*(double_cross + y)))) == null)
        {
            *result = null;
            _destroy(first_cross);
            _destroy(second_cross);
            _destroy(&double_cross);
            return 3;
        }
        else
        {
            *(double_cross + y) = temp;
        }
    }

    //=
    // Insert second cross
    //=
    for (cstring* out_row = (double_cross + start_i), *in_row = (*second_cross);
        out_row < (double_cross + end_ie);
        ++out_row, ++in_row)
    {
        if ((temp = alloc_string_append(*out_row, *in_row, 1)) == null)
        {
            *result = null;
            _destroy(first_cross);
            _destroy(second_cross);
            _destroy(&double_cross);
            return 3;
        }
        else
        {
            *out_row = temp;
        }
    }

    *result = double_cross;
    return 0;
}

void destroy(cstring* words)
{
    _destroy(&words);
}

void _print_cross(cstring* cross)
{
    for (cstring* line = cross; *line != null; ++line)
    {
        printf_ln("%s", *line);
    }

}

