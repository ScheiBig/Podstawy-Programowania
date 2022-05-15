#pragma once

#include "my_utils_v2.h"
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
