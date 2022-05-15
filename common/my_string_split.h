#pragma once

#include "my_utils_v2.h"
#include <string.h>

typedef struct
{
    c_cstring start_ptr;
    size_t length;
    c_cstring delimiters;
} token;

token string_split(c_cstring str, c_cstring delimiters)
{
    if (str == null || strlen(str) == 0 || delimiters == null || strlen(delimiters) == 0)
    {
        return (token) { .start_ptr = null, .length = 0, .delimiters = null };
    }
    c_cstring cur_match = str;
    c_cstring next_match = strpbrk(cur_match, delimiters);
    size_t len = strlen(cur_match);
    while (true)
    {
        if (next_match == null)
        {
            return (token) { .start_ptr = str, .length = len, .delimiters = null };
        }
        if (next_match - cur_match == 0)
        {
            next_match = strpbrk(++cur_match, delimiters);
            continue;
        }
        return (token) { .start_ptr = cur_match, .length = (size_t)(next_match - cur_match), .delimiters = delimiters };
    }
}

token string_split_next(token prev)
{
    if (prev.start_ptr == null || prev.delimiters == null || prev.length == 0)
    {
        return (token) { .start_ptr = null, .length = 0, .delimiters = null };
    }
    return string_split(prev.start_ptr + prev.length + 1, prev.delimiters);
}

size_t string_split_count(c_cstring str, c_cstring delimiters)
{
    if (str == null || strlen(str) == 0 || delimiters == null || strlen(delimiters) == 0)
    {
        return 0;
    }
    size_t count = 0;
    for (
        token tok = string_split(str, delimiters);
        tok.start_ptr != null;
        tok = string_split_next(tok)
        )
    {
        ++count;
    }
    return count;
}
