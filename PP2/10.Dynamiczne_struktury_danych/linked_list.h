#pragma once

typedef struct node_t
{
    int data;
    struct node_t* next;
} node_s;

typedef struct linked_list_t
{
    node_s* head;
    node_s* tail;
} linked_list_s;

linked_list_s* ll_create();

int ll_push_back(linked_list_s* ll, int value);
int ll_push_front(linked_list_s* ll, int value);
int ll_pop_back(linked_list_s* ll, int* err_code);
int ll_pop_front(linked_list_s* ll, int* err_code);

int ll_back(const linked_list_s* ll, int* err_code);
int ll_front(const linked_list_s* ll, int* err_code);

node_s* ll_end(linked_list_s* ll);
node_s* ll_begin(linked_list_s* ll);

int ll_size(const linked_list_s* ll);
int ll_is_empty(const linked_list_s* ll);
int ll_at(const linked_list_s* ll, unsigned int index, int* err_code);

int ll_insert(linked_list_s* ll, unsigned int index, int value);

int ll_remove(linked_list_s* ll, unsigned int index, int* err_code);

void ll_clear(linked_list_s* ll);

void ll_display(const linked_list_s* ll);

struct linked_list_i
{
    linked_list_s* (*create) (void);

    int (*push_back) (linked_list_s* ll, int value);
    int (*push_front) (linked_list_s* ll, int value);
    int (*pop_back) (linked_list_s* ll, int* err_code);
    int (*pop_front) (linked_list_s* ll, int* err_code);

    int (*back) (const linked_list_s* ll, int* err_code);
    int (*front) (const linked_list_s* ll, int* err_code);

    node_s* (*end) (linked_list_s* ll);
    node_s* (*begin) (linked_list_s* ll);

    int (*size) (const linked_list_s* ll);
    int (*is_empty) (const linked_list_s* ll);
    int (*at) (const linked_list_s* ll, unsigned int index, int* err_code);

    int (*insert) (linked_list_s* ll, unsigned int index, int value);

    int (*remove) (linked_list_s* ll, unsigned int index, int* err_code);

    void (*clear) (linked_list_s* ll);

    void (*display) (const linked_list_s* ll);
};

extern const struct linked_list_i LIST;