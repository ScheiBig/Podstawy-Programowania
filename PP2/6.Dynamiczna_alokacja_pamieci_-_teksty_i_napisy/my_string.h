#pragma once

#include "my_utils_v3.h"
#include <string.h>

int discard_stdin()
{
    int count = 0;
    while (fgetc(stdin) != '\n') ++count;
    return count;
}


int discard_stream(p_file stream)
{
    int count = 0;
    while (fgetc(stream) != '\n') ++count;
    return count;
}


cstring string_prepend_c(cstring string, char prefix)
{
    int len = strlen(string) + 1;
    for (int i = len; i >= 1; --i)
    {
        *(string + i) = *(string + i - 1);
    }
    *(string) = prefix;
    return string;
}

cstring string_prepend(cstring string, cstring prefix)
{
    for (char* c = prefix; (*c) != str_term; ++c)
    {
        string_prepend_c(string, (*c));
    }
    return string;
}


cstring string_append_c(cstring string, char suffix)
{
    int len = strlen(string);
    *(string + len) = suffix;
    return string;
}

cstring string_append(cstring string, cstring suffix)
{
    for (char* c = suffix; (*c) != str_term; ++c)
    {
        string_append_c(string, (*c));
    }
    return string;
}


int string_endswith(c_cstring str, c_cstring end)
{
    if (str == NULL || end == NULL)
    {
        return -1;
    }
    size_t str_l = strlen(str);
    size_t end_l = strlen(end);
    if (str_l < end_l)
    {
        return -1;
    }
    int ret = 1;
    c_cstring s = str + str_l - end_l;

    for (size_t e = 0; e < end_l; ++e)
    {
        ret *= (*(s + e) == *(end + e));
    }
    if (ret) return 1;

    return 0;
}

cstring strncpy_term(cstring dest, c_cstring src, size_t N)
{
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    cstring ret = strncpy(dest, src, N);
    *(dest + N) = str_term;
    return ret;
}


void string_reverse(cstring str)
{
    size_t str_len = strlen(str);
    char temp;
    for (size_t i = 0; i < str_len / 2; ++i)
    {
        temp = *(str + i);
        *(str + i) = *(str + str_len - i - 1);
        *(str + str_len - i - 1) = temp;
    }
}

void string_reverse_lim(cstring str, size_t lim)
{
    size_t str_len = min(strlen(str), lim);
    char temp;
    for (size_t i = 0; i < str_len / 2; ++i)
    {
        temp = *(str + i);
        *(str + i) = *(str + str_len - i - 1);
        *(str + str_len - i - 1) = temp;
    }
}