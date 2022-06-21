#pragma once

#include "my_utils_v3.h"
#include <string.h>
#include <stdbool.h>

typedef struct
{
    // Pointer to start of token resulting from splitting. As pointer is in memory space of processed string,
    // it is NOT null-terminated at the end of token
    c_cstring start_ptr;
    // Length of string resulting from splitting, needs to be used in further processing, as this#start_ptr
    // is not null-terminated after `length` characters
    size_t length;
    // Pointer of string passed to #strpbrk(%, %). If in this result address of delimiters is `null`, this token 
    // is last token in string being processed
    c_cstring delimiters;
} token;

#define token_empty (token) { .start_ptr = null, .length = 0, .delimiters = null }

token string_split(c_cstring str, c_cstring delimiters)
{
    if (str == null || strlen(str) == 0 || delimiters == null || strlen(delimiters) == 0)
    {
        return token_empty;
    }
    c_cstring cur_match = str;
    c_cstring next_match = strpbrk(cur_match, delimiters);
    while (true)
    {
        if (strlen(cur_match) == 0) { return token_empty; }
        else if (next_match == null)
        {
            return (token) { .start_ptr = cur_match, .length = strlen(cur_match), .delimiters = null };
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
        return token_empty;
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

token token_trim_spaces(token tok)
{
    if (tok.start_ptr == null || tok.delimiters == null || tok.length == 0)
    {
        return token_empty;
    }
    cstring st_ptr = (cstring)tok.start_ptr;
    size_t len = tok.length;

    for (; *st_ptr == ' '; ++st_ptr, --len);
    for (; *(st_ptr + len - 1) == ' '; --len)
    {
        null;
    }

    return (token) { .start_ptr = st_ptr, .length = len, .delimiters = tok.delimiters };
}

token string_split_e(c_cstring str, c_cstring delimiters)
{
    if (str == null || delimiters == null || strlen(delimiters) == 0)
    {
        return token_empty;
    }
    c_cstring cur_match = str;
    c_cstring next_match = strpbrk(cur_match, delimiters);
    while (true)
    {
        if (next_match == null)
        {
            return (token) { .start_ptr = cur_match, .length = strlen(cur_match), .delimiters = null };
        }
        return (token) { .start_ptr = cur_match, .length = (size_t)(next_match - cur_match), .delimiters = delimiters };
    }
}

token string_split_next_e(token prev)
{
    if (prev.start_ptr == null || prev.delimiters == null)
    {
        return token_empty;
    }
    return string_split_e(prev.start_ptr + prev.length + 1, prev.delimiters);
}

size_t string_split_count_e(c_cstring str, c_cstring delimiters)
{
    if (str == null || delimiters == null || strlen(delimiters) == 0)
    {
        return 0;
    }
    size_t count = 0;
    for (
        token tok = string_split_e(str, delimiters);
        tok.start_ptr != null;
        tok = string_split_next_e(tok)
        )
    {
        ++count;
    }
    return count;
}
