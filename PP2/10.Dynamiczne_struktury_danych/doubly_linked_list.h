#pragma once

typedef struct node_t
{
    int data;
    struct node_t* next;
    struct node_t* prev;
} node_s;

typedef struct doubly_linked_list_t
{
    node_s* head;
    node_s* tail;
} doubly_linked_list_s;

doubly_linked_list_s* dll_create();

int dll_push_back(doubly_linked_list_s* dll, int value);
int dll_push_front(doubly_linked_list_s* dll, int value);
int dll_pop_front(doubly_linked_list_s* dll, int* err_code);
int dll_pop_back(doubly_linked_list_s* dll, int* err_code);

int dll_back(const doubly_linked_list_s* dll, int* err_code);
int dll_front(const doubly_linked_list_s* dll, int* err_code);

node_s* dll_begin(doubly_linked_list_s* dll);
node_s* dll_end(doubly_linked_list_s* dll);

int dll_size(const doubly_linked_list_s* dll);
int dll_is_empty(const doubly_linked_list_s* dll);

int dll_at(const doubly_linked_list_s* dll, unsigned int index, int* err_code);

int dll_insert(doubly_linked_list_s* dll, unsigned int index, int value);
int dll_remove(doubly_linked_list_s* dll, unsigned int index, int* err_code);

void dll_clear(doubly_linked_list_s* dll);

void dll_display(const doubly_linked_list_s* dll);
void dll_display_reverse(const doubly_linked_list_s* dll);

struct linked_list_i
{
    doubly_linked_list_s* (*create) (void);

    int (*push_back) (doubly_linked_list_s* ll, int value);
    int (*push_front) (doubly_linked_list_s* ll, int value);
    int (*pop_back) (doubly_linked_list_s* ll, int* err_code);
    int (*pop_front) (doubly_linked_list_s* ll, int* err_code);

    int (*back) (const doubly_linked_list_s* ll, int* err_code);
    int (*front) (const doubly_linked_list_s* ll, int* err_code);

    node_s* (*end) (doubly_linked_list_s* ll);
    node_s* (*begin) (doubly_linked_list_s* ll);

    int (*size) (const doubly_linked_list_s* ll);
    int (*is_empty) (const doubly_linked_list_s* ll);
    int (*at) (const doubly_linked_list_s* ll, unsigned int index, int* err_code);

    int (*insert) (doubly_linked_list_s* ll, unsigned int index, int value);

    int (*remove) (doubly_linked_list_s* ll, unsigned int index, int* err_code);

    void (*clear) (doubly_linked_list_s* ll);

    void (*display) (const doubly_linked_list_s* ll);
    void (*display_reverse) (const doubly_linked_list_s* ll);
};

extern const struct linked_list_i LIST;