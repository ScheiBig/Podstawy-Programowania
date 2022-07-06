#include "dictionary.h"

#include <stdlib.h>
#include <string.h>

#include "my_utils_v3.h"

dictionary create_dictionary(int N, int* err_code)
{
    if (N <= 0)
    {
        cond_assign_nn(err_code, 1);
        return null;
    }

    dictionary d = (dictionary)calloc(1u, sizeof(struct dictionary_t));
    if (d == null)
    {
        cond_assign_nn(err_code, 2);
        return null;
    }

    d->wc = (word_count)calloc((unsigned)N, sizeof(struct word_count_t));
    if (d->wc == null)
    {
        free(d);
        cond_assign_nn(err_code, 2);
        return null;
    }
    d->capacity = N;

    cond_assign_nn(err_code, 0);
    return d;
}

void destroy_dictionary(dictionary* d)
{
    if (d == null || *d == null) { return; }
    dictionary p = *d;
    if (p->capacity <= 0 || p->size < 0 || p->size > p->capacity) { return; }
    if (p->wc == null)
    {
        free(p);
        *d = null;
        return;
    }
    for (ssize_t i = 0; i < p->size; ++i)
    {
        if ((p->wc + i)->word != null) { free((p->wc + i)->word); }
    }
    free(p->wc);
    free(p);
    *d = null;
}

int dictionary_add_word(dictionary d, c_cstring word)
{
    if (d == null || d->capacity <= 0 || d->size < 0 || d->size > d->capacity ||
        d->wc == null || word == null || strlen(word) == 0)
    {
        return 1;
    }
    word_count w_c = dictionary_find_word(d, word);
    if (w_c == null)
    {
        if (d->size == d->capacity)
        {
            word_count new_wc = (word_count)realloc(d->wc, ((unsigned)d->capacity * 2) * sizeof(struct word_count_t));
            if (new_wc == null) { return 2; }
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            memset(new_wc + d->capacity, 0x0, d->capacity * sizeof(struct word_count_t));
            d->wc = new_wc;
            d->capacity *= 2;
        }
        w_c = d->wc + d->size;
        w_c->word = strdup(word);
        if (w_c->word == null) { return 2; }
        ++(d->size);
    }
    ++(w_c->counter);
    return 0;
}

word_count dictionary_find_word(c_dictionary d, c_cstring word)
{
    if (d == null || d->capacity <= 0 || d->size < 0 || d->size > d->capacity ||
        d->wc == null || word == null || strlen(word) == 0)
    {
        return null;
    }
    for (word_count s = d->wc; s < d->wc + d->size; ++s) { if (strcmp(s->word, word) == 0) { return s; } }
    return null;
}

void dictionary_display(c_dictionary d)
{
    if (d == null || d->capacity <= 0 || d->size < 0 || d->size > d->capacity || d->wc == null) { return; }
    for (word_count s = d->wc; s < d->wc + d->size; ++s) { printf_ln("%s %d", s->word, s->counter); }
}
