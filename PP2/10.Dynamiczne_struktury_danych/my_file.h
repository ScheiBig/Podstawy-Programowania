#pragma once

#include "my_utils_v3.h"
#include <string.h>
#include <stdbool.h>

typedef struct
{
    long start_pos;
    size_t length;
    c_cstring delimiters;
    p_file src_stream;
} stream_token;

long streamposbrk(p_file stream, long start_pos, c_cstring delimiters)
{
    if (stream == null || delimiters == null || strlen(delimiters) == 0 || start_pos < 0)
    {
        return EOF;
    }
    long prev_pos = ftell(stream);
    fseek(stream, start_pos, SEEK_SET);
    c_cstring scan_ptr;
    int read_chr;

    while ((read_chr = getc(stream)) != EOF)
    {
        for (scan_ptr = delimiters; *scan_ptr != str_term; ++scan_ptr)
        {
            if (read_chr == *scan_ptr)
            {
                long pos = ftell(stream) - 1;
                fseek(stream, prev_pos, SEEK_SET);
                return pos;
            }
        }
    }
    fseek(stream, prev_pos, SEEK_SET);
    return EOF;
}

stream_token stream_split(p_file stream, long start_pos, c_cstring delimiters)
{    if (stream == null || feof(stream) || delimiters == null || strlen(delimiters) == 0)
    {
        return (stream_token) { .start_pos = EOF, .length = 0, .delimiters = null, .src_stream = null };
    }
    long cur_pos = start_pos;
    long next_match = streamposbrk(stream, cur_pos, delimiters);
    size_t len = next_match - cur_pos;
    while (true)
    {
        if (next_match == EOF)
        {
            return (stream_token) { .start_pos = cur_pos, .length = len, .delimiters = null, .src_stream = stream };
        }
        return (stream_token) { .start_pos = cur_pos, .length = len, .delimiters = delimiters, .src_stream = stream };
    }
}

stream_token stream_split_next(stream_token prev)
{
    if (prev.start_pos == EOF || prev.delimiters == null || prev.src_stream == null)
    {
        return (stream_token) { .start_pos = EOF, .length = 0, .delimiters = null, .src_stream = null };
    }
    return stream_split(prev.src_stream, prev.start_pos + prev.length + 1, prev.delimiters);
}

size_t stream_split_count(p_file stream, long start_pos, c_cstring delimiters)
{
    if (stream == null || delimiters == null || strlen(delimiters) == 0 || start_pos < 0)
    {
        return 0;
    }
    size_t count = 0;
    for (
        stream_token tok = stream_split(stream, start_pos, delimiters);
        tok.start_pos != EOF;
        tok = stream_split_next(tok)
        )
    {
        ++count;
    }
    return count;
}

char* stream_to_string_cpy(cstring dest, p_file src, long start_pos, size_t N)
{
    if (dest == null || src == null || start_pos < 0 || N == 0)
    {
        return null;
    }
    long cur_pos = ftell(src);
    fseek(src, start_pos, SEEK_SET);
    int chr = getc(src);
    size_t n;
    for (n = 0; n < N && chr != EOF; ++n, chr = getc(src))
    {
        *(dest + n) = (char)chr;
    }
    *(dest + n) = str_term;
    fseek(src, cur_pos, SEEK_SET);
    return dest;
}
