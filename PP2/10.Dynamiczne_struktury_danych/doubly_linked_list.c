#include "doubly_linked_list.h"
#include "my_utils_v3.h"

const struct linked_list_i LIST = {
    .create = dll_create,
    .push_back = dll_push_back,
    .push_front = dll_push_front,
    .pop_back = dll_pop_back,
    .pop_front = dll_pop_front,
    .back = dll_back,
    .front = dll_front,
    .end = dll_end,
    .begin = dll_begin,
    .size = dll_size,
    .is_empty = dll_is_empty,
    .at = dll_at,
    .insert = dll_insert,
    .remove = dll_remove,
    .clear = dll_clear,
    .display = dll_display,
    .display_reverse = dll_display_reverse
};

doubly_linked_list_s* dll_create()
{
    doubly_linked_list_s* list = (doubly_linked_list_s*)MEMORY.allocate_empty(1, sizeof(doubly_linked_list_s));
    if (list == null) { return null; }
    else { return list; }
}

int dll_push_back(doubly_linked_list_s* dll, int value)
{
    if (LIST.is_empty(dll) == -1) { return 1; }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = value;

    if (LIST.is_empty(dll)) { dll->head = new_node; }
    else
    {
        dll->tail->next = new_node;
        new_node->prev = dll->tail;
    }

    dll->tail = new_node;
    return 0;
}

int dll_push_front(doubly_linked_list_s* dll, int value)
{
    if (LIST.is_empty(dll) == -1) { return 1; }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = value;

    if (LIST.is_empty(dll)) { dll->tail = new_node; }
    else
    {
        dll->head->prev = new_node;
        new_node->next = dll->head;
    }

    dll->head = new_node;
    return 0;
}

int dll_pop_back(doubly_linked_list_s* dll, int* err_code)
{
    if (LIST.is_empty(dll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (dll->head == dll->tail)
    {
        int ret = dll->head->data;
        MEMORY.release(dll->head);
        dll->head = dll->tail = null;
        cond_assign_nn(err_code, 0);
        return ret;
    }

    node_s* last = dll->tail;
    node_s* prev = dll->tail->prev;

    prev->next = null;
    dll->tail = prev;

    int ret = last->data;
    MEMORY.release(last);

    cond_assign_nn(err_code, 0);
    return ret;
}

int dll_pop_front(doubly_linked_list_s* dll, int* err_code)
{
    if (LIST.is_empty(dll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (dll->head == dll->tail)
    {
        int ret = dll->head->data;
        MEMORY.release(dll->head);
        dll->head = dll->tail = null;
        cond_assign_nn(err_code, 0);
        return ret;
    }

    node_s* first = dll->head;
    node_s* next = dll->head->next;

    next->prev = null;
    dll->head = next;

    int ret = first->data;
    MEMORY.release(first);

    cond_assign_nn(err_code, 0);
    return ret;
}

int dll_back(const doubly_linked_list_s* dll, int* err_code)
{
    if (LIST.is_empty(dll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    cond_assign_nn(err_code, 0);
    return dll->tail->data;
}

int dll_front(const doubly_linked_list_s* dll, int* err_code)
{
    if (LIST.is_empty(dll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    cond_assign_nn(err_code, 0);
    return dll->head->data;
}

node_s* dll_end(doubly_linked_list_s* dll)
{
    if (LIST.is_empty(dll)) { return null; }
    return dll->tail;
}

node_s* dll_begin(doubly_linked_list_s* dll)
{
    if (LIST.is_empty(dll)) { return null; }
    return dll->head;
}

int dll_size(const doubly_linked_list_s* dll)
{
    switch (LIST.is_empty(dll))
    {
    case -1: return -1;
    case 1: return 0;
    }
    int size;
    node_s* cur;
    for (size = 1, cur = dll->head; cur->next != null; ++size, cur = cur->next);

    return size;
}

int dll_is_empty(const doubly_linked_list_s* dll)
{
    if (dll == null || (dll->head == null && dll->tail != null)) { return -1; }
    return dll->head == null;
}

int dll_at(const doubly_linked_list_s* dll, unsigned int index, int* err_code)
{
    if (LIST.is_empty(dll) || index >= (unsigned)LIST.size(dll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }
    unsigned int in;
    node_s* cur;
    for (in = 0, cur = dll->head; in != index; ++in, cur = cur->next);

    cond_assign_nn(err_code, 0);
    return cur->data;
}

int dll_insert(doubly_linked_list_s* dll, unsigned int index, int value)
{
    unsigned int size = (unsigned)LIST.size(dll);
    if (LIST.is_empty(dll) == -1 || index > size)
    {
        return 1;
    }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = value;

    if (index == 0)
    {
        new_node->next = dll->head;
        if (dll->head != null) { dll->head->prev = new_node; }
        dll->head = new_node;
        if (dll->tail == null) { dll->tail = new_node; }
        return 0;
    }

    if (index == size)
    {
        dll->tail->next = new_node;
        new_node->prev = dll->tail;
        dll->tail = new_node;
        return 0;
    }

    unsigned int in;
    node_s* cur;
    for (in = 0, cur = dll->head; in < index - 1; ++in, cur = cur->next);

    node_s* next = cur->next;
    cur->next = new_node;
    new_node->prev = cur;
    next->prev = new_node;
    new_node->next = next;
    return 0;
}

int dll_remove(doubly_linked_list_s* dll, unsigned int index, int* err_code)
{
    unsigned int size = (unsigned)LIST.size(dll);
    if (LIST.is_empty(dll) == -1 || index >= size)
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (index == 0)
    {
        node_s* first = dll->head;
        node_s* next = dll->head->next;
        dll->head = next;
        if (next == null) { dll->tail = next; }
        else { next->prev = null; }

        int ret = first->data;
        MEMORY.release(first);

        cond_assign_nn(err_code, 0);
        return ret;
    }

    if (index == size - 1)
    {
        node_s* last = dll->tail;
        node_s* prev = dll->tail->prev;
        dll->tail = prev;
        prev->next = null;

        int ret = last->data;
        MEMORY.release(last);

        cond_assign_nn(err_code, 0);
        return ret;
    }

    unsigned int in;
    node_s* cur;
    for (in = 0, cur = dll->head; in < index - 1; ++in, cur = cur->next);

    node_s* next = cur->next;
    node_s* nnext = cur->next->next;

    cur->next = nnext;
    nnext->prev = cur;

    int ret = next->data;
    MEMORY.release(next);

    cond_assign_nn(err_code, 0);
    return ret;
}

void dll_clear(doubly_linked_list_s* dll)
{
    if (dll == null || LIST.is_empty(dll)) { return; }
    while (!LIST.is_empty(dll)) { LIST.pop_back(dll, null); }
}

void dll_display(const doubly_linked_list_s* dll)
{
    if (LIST.is_empty(dll)) { return; }
    for (node_s* n = dll->head; n != null; n = n->next) { printf("%d ", n->data); }
    print_n();
}

void dll_display_reverse(const doubly_linked_list_s* dll)
{
    if (LIST.is_empty(dll)) { return; }
    for (node_s* n = dll->tail; n != null; n = n->prev) { printf("%d ", n->data); }
    print_n();
}