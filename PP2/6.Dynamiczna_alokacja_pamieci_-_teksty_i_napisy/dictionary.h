#pragma once

typedef struct word_count_t
{
    char* word;
    int counter;
}*word_count;

typedef struct dictionary_t
{
    int size;
    int capacity;
    word_count wc;
}*dictionary;

typedef const struct dictionary_t* c_dictionary;

dictionary create_dictionary(int N, int* err_code);
void destroy_dictionary(dictionary* d);

int dictionary_add_word(dictionary d, const char* word);
word_count dictionary_find_word(c_dictionary d, const char* word);

void dictionary_display(c_dictionary d);