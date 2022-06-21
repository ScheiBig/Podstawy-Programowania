#include "my_string.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "my_utils_v3.h"

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

void string_flip_case(cstring str)
{
    for (char* c = str; *c != str_term; ++c)
    {
        if (!isalpha(*c)) continue;
        else if (islower(*c)) *c -= 0x20;
        else if (isupper(*c)) *c += 0x20;
    }
}

cstring alloc_string_append(cstring string, cstring suffix, size_t repeat_times)
{
    if (string == null)
    {
        return null;
    }
    size_t s_len = strlen(suffix);
    if (suffix == null || s_len == 0 || repeat_times == 0)
    {
        return string;
    }
    size_t len = strlen(string);
    size_t new_len = len + strlen(suffix) * repeat_times;
    cstring new_string = (cstring)realloc(string, new_len + 1);
    if (new_string == null)
    {
        return null;
    }
    for (size_t i = 0, pos = len; i < repeat_times; ++i, pos += strlen(suffix))
    {
        strcpy((new_string + pos), suffix); // NOLINT
    }
    return new_string;
}

cstring alloc_string_prepend(cstring string, cstring prefix, size_t repeat_times)
{
    if (string == null)
    {
        return null;
    }
    size_t p_len = strlen(prefix);
    if (prefix == null || p_len == 0 || repeat_times == 0)
    {
        return string;
    }
    size_t len = strlen(string);
    size_t new_len = len + p_len * repeat_times;
    cstring new_string = (cstring)realloc(string, new_len + 1);
    if (new_string == null)
    {
        return null;
    }
    memmove(new_string + p_len, new_string, len + 1); // NOLINT
    for (size_t i = 0, pos = 0; i < repeat_times; ++i, pos += p_len)
    {
        strncpy((new_string + pos), prefix, p_len); // NOLINT
    }
    return new_string;
}

size_t pagelen(cstring* page)
{
    if (page == null || *page == null)
    {
        return 0;
    }
    size_t size = 0;
    for (cstring* ptr = page; *ptr != null; ++ptr, ++size);
    return size;
}

cstring* alloc_string_page_append(cstring* page, size_t num_of_lines)
{
    if (page == null)
    {
        return null;
    }
    if (num_of_lines == 0)
    {
        return page;
    }
    size_t p_len = pagelen(page);
    cstring* new_page = (cstring*)realloc(page, (p_len + num_of_lines + 1) * sizeof(cstring));
    if (new_page == null)
    {
        return null;
    }
    for (size_t i = 0; i < num_of_lines; ++i)
    {
        *(new_page + p_len + i) = (cstring)calloc(1, sizeof(char));
    }
    *(new_page + p_len + num_of_lines) = null;
    return new_page;
}

cstring* alloc_string_page_prepend(cstring* page, size_t num_of_lines)
{
    if (page == null)
    {
        return null;
    }
    if (num_of_lines == 0)
    {
        return page;
    }
    size_t p_len = pagelen(page);
    cstring* new_page = (cstring*)realloc(page, (p_len + num_of_lines + 1) * sizeof(cstring));
    if (new_page == null)
    {
        return null;
    }
    memmove(new_page + num_of_lines, new_page, (p_len + 1) * sizeof(cstring)); // NOLINT
    for (size_t i = 0; i < num_of_lines; ++i)
    {
        *(new_page + i) = (cstring)calloc(1, sizeof(char));
    }
    return new_page;
}
