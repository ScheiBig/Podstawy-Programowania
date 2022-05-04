#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IS_LETTER(A) ('a' <= A && A <= 'z' || 'A' <= A && A <= 'Z')

#define BUF_LEN 1000
#define WRD_LEN 501

typedef struct _word
{
    size_t length;
    size_t start_i;
    size_t end_i;
} word;

typedef enum _char_tp
{
    whitespace, letter, none
} char_tp;

int main()
{

    char buffer[BUF_LEN + 1] = { (char)0 };
    printf("Enter your string: ");
    fgets(buffer, BUF_LEN + 1, stdin);
    if (buffer[strlen(buffer) - 1] <= ' ')
    {
        buffer[strlen(buffer) - 1] = (char)0;
    }

    size_t str_len = strlen(buffer),
        wrd_count = 0u,
        // white = 0u,
        alph = 0u;
    word words[WRD_LEN],
        * current_w;
    char_tp type = none;
    for (size_t i = 0; i < str_len + 1; ++i)
    {
        if (IS_LETTER(buffer[i]))
        {
            if (type == whitespace || type == none)
            {
                type = letter;
                alph = i;
            }
        }
        else if (buffer[i] == ' ' || buffer[i] == (char)0)
        {
            if (type == letter)
            {
                type = whitespace;
                current_w = words + (wrd_count++);
                current_w->start_i = alph;
                current_w->end_i = i;
                current_w->length = i - alph;
            }
        }
        else
        {
            fprintf(stderr, "Incorrect input\n");
            return 1;
        }
    }

    size_t lngst_w_cnt = 0u,
        lngst_w_len = 0u,
        lngst_w_i[WRD_LEN];
    for (size_t i = 0; i < wrd_count; ++i)
    {
        current_w = words + i;
        if (lngst_w_len < current_w->length)
        {
            lngst_w_len = current_w->length;
            lngst_w_cnt = 0u;
            lngst_w_i[lngst_w_cnt++] = i;
        }
        else if (lngst_w_len == current_w->length)
        {
            lngst_w_i[lngst_w_cnt++] = i;
        }
    }
    printf("%zu %zu\n", lngst_w_cnt, lngst_w_len);
    for (size_t i = lngst_w_cnt; i > 0; --i)
    {
        printf("%.*s\n", (int)lngst_w_len, buffer + words[lngst_w_i[i - 1]].start_i);
    }

    return 0;
}
