#pragma once

typedef struct node_t
{
    char*  data;
    struct node_t* next;
} node_s;

typedef struct linked_list_t
{
    node_s* head;
    node_s* tail;
} linked_list_s;

linked_list_s* ll_create();

int ll_push_back(linked_list_s* ll, char* value);
int ll_push_front(linked_list_s* ll, char* value);

int ll_size(const linked_list_s* ll);
int ll_is_empty(const linked_list_s* ll);

void ll_clear(linked_list_s* ll);

void ll_display(const linked_list_s* ll);

int ll_is_sorted_ascending(const struct linked_list_t* ll);
int ll_insert_words(struct linked_list_t* ll, int N, ...);

struct linked_list_i
{
    linked_list_s* (*create) (void);

    int (*push_back) (linked_list_s* ll, char* value);
    int (*push_front) (linked_list_s* ll, char* value);

    node_s* (*end) (linked_list_s* ll);
    node_s* (*begin) (linked_list_s* ll);

    int (*size) (const linked_list_s* ll);
    int (*is_empty) (const linked_list_s* ll);

    void (*clear) (linked_list_s* ll);

    void (*display) (const linked_list_s* ll);

    int (*is_sorted_ascending) (const struct linked_list_t* ll);
    int (*insert_words) (struct linked_list_t* ll, int N, ...);

};

extern const struct linked_list_i LIST;