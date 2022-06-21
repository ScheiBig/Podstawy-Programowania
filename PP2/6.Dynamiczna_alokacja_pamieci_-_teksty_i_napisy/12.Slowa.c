#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

#include "my_utils_v3.h"
#include "my_string.h"
#include "my_string_split.h"

cstring* split_words(c_cstring text);
int sort_words(cstring* words);
void destroy(cstring* words);

int cant_alloc = 0;

int main()
{
    cstring text = (cstring)calloc(1000, sizeof(char));
    if (text == null) { __m_exit(eMEMORY_cantallocate); }
    print_ln("Enter a string:");
    fgets(text, 1000, stdin);
    cstring* words = split_words(text);
    if (words == null && cant_alloc)
    {
        free(text);
        __m_exit(eMEMORY_cantallocate);
    }
    else if (words == null)
    {
        free(text);
        destroy(words);
        _m_exit(0, "Nothing to show");
    }
    sort_words(words);
    for (cstring* c = words; *c != null; ++c) { printf_ln("%s", *c); }

    free(text);
    destroy(words);

    return 0;
}

cstring* split_words(c_cstring text)
{
    if (text == null || strlen(text) == 0) { return null; }

    size_t words_count = string_split_count(text, ASCIIset_numbers ASCIIset_symbols ASCIIset_unprintable);
    if (words_count == 0) { return null; }

    cstring* words = (cstring*)calloc(words_count + 1, sizeof(cstring));
    if (words == null)
    {
        cant_alloc = 1;
        return null;
    }

    size_t ctn = 0;
    for (token tok = string_split(text, ASCIIset_numbers ASCIIset_symbols ASCIIset_unprintable); tok.start_ptr != null;
        tok = string_split_next(tok),
        ++ctn)
    {
        *(words + ctn) = (cstring)calloc(tok.length + 1, sizeof(char));
        if (*(words + ctn) == null)
        {
            cant_alloc = 1;
            destroy(words);
            return null;
        }
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        strncpy(*(words + ctn), tok.start_ptr, tok.length);
    }
    return words;
}

static int str_cmp(const void* s1, const void* s2) { return strcmp(*(c_cstring*)s1, *(c_cstring*)s2); }

int sort_words(cstring* words)
{
    if (words == null) { return 1; }
    if (*words == null) { return 1; }
    if (*(words + 1) == null) { return 0; }
    size_t word_count = 0;
    for (cstring* c = words; *c != null; ++c, ++word_count);
    qsort(words, word_count, sizeof(cstring), str_cmp);
    return 0;
}

void destroy(cstring* words)
{
    if (words == null) { return; }
    if (*words == null)
    {
        free(words);
        return;
    }
    for (cstring* c = words; *c != null; ++c) { free(*c); }
    free(words);
    return;
}
