#include "linked_list.h"

#include "my_utils_v3.h"

const struct linked_list_i LIST = {
    .create = ll_create,
    .push_back = ll_push_back,
    .push_front = ll_push_front,
    .pop_back = ll_pop_back,
    .pop_front = ll_pop_front,
    .back = ll_back,
    .front = ll_front,
    .end = ll_end,
    .begin = ll_begin,
    .size = ll_size,
    .is_empty = ll_is_empty,
    .at = ll_at,
    .insert = ll_insert,
    .remove = ll_remove,
    .clear = ll_clear,
    .display = ll_display
};

linked_list_s* ll_create()
{
    linked_list_s* list = (linked_list_s*)MEMORY.allocate_empty(1, sizeof(linked_list_s));
    if (list == null) { return null; }
    else { return list; }
}

int ll_push_back(linked_list_s* ll, int value)
{
    if (LIST.is_empty(ll) == -1) { return 1; }
    
    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = value;
    
    if (LIST.is_empty(ll)) { ll->head = new_node; }
    else { ll->tail->next = new_node; }
    
    ll->tail = new_node;
    return 0;
}

int ll_push_front(linked_list_s* ll, int value)
{
    if (LIST.is_empty(ll) == -1) { return 1; }
    
    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = value;
    
    if (LIST.is_empty(ll)) { ll->tail = new_node; }
    new_node->next = ll->head;
    
    ll->head = new_node;
    return 0;
}

int ll_pop_back(linked_list_s* ll, int* err_code)
{
    if (LIST.is_empty(ll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (ll->head == ll->tail)
    {
        int ret = ll->head->data;
        MEMORY.release(ll->head);
        ll->head = ll->tail = null;
        cond_assign_nn(err_code, 0);
        return ret;
    }

    node_s* last = ll->tail;
    node_s* prev;
    for (prev = ll->head; prev->next != last; prev = prev->next);

    prev->next = null;
    ll->tail = prev;

    int ret = last->data;
    MEMORY.release(last);

    cond_assign_nn(err_code, 0);
    return ret;
}

int ll_pop_front(linked_list_s* ll, int* err_code)
{
    if (LIST.is_empty(ll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (ll->head == ll->tail)
    {
        int ret = ll->head->data;
        MEMORY.release(ll->head);
        ll->head = ll->tail = null;
        cond_assign_nn(err_code, 0);
        return ret;
    }

    node_s* first = ll->head;
    node_s* next = ll->head->next;

    ll->head = next;

    int ret = first->data;
    MEMORY.release(first);

    cond_assign_nn(err_code, 0);
    return ret;
}

int ll_back(const linked_list_s* ll, int* err_code)
{
    if (LIST.is_empty(ll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (ll->head == ll->tail)
    {
        cond_assign_nn(err_code, 0);
        return ll->head->data;
    }

    cond_assign_nn(err_code, 0);
    return ll->tail->data;
}

int ll_front(const linked_list_s* ll, int* err_code)
{
    if (LIST.is_empty(ll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    cond_assign_nn(err_code, 0);
    return ll->head->data;
}

node_s* ll_end(linked_list_s* ll)
{
    if (LIST.is_empty(ll)) { return null; }
    return ll->tail;
}
node_s* ll_begin(linked_list_s* ll)
{
    if (LIST.is_empty(ll)) { return null; }
    return ll->head;
}

int ll_size(const linked_list_s* ll)
{
    switch (LIST.is_empty(ll))
    {
    case -1: return -1;
    case 1: return 0;
    }
    int size;
    node_s* cur;
    for (size = 1, cur = ll->head; cur->next != null; ++size, cur = cur->next);

    return size;
}
int ll_is_empty(const linked_list_s* ll)
{
    if (ll == null || (ll->head == null && ll->tail != null)) { return -1; }
    return ll->head == null;
}
int ll_at(const linked_list_s* ll, unsigned int index, int* err_code)
{
    if (LIST.is_empty(ll) || index >= (unsigned)LIST.size(ll))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }
    unsigned int in;
    node_s* cur;
    for (in = 0, cur = ll->head; in != index; ++in, cur = cur->next);

    cond_assign_nn(err_code, 0);
    return cur->data;
}

int ll_insert(linked_list_s* ll, unsigned int index, int value)
{
    unsigned int size = (unsigned)LIST.size(ll);
    if (LIST.is_empty(ll) == -1 || index > size)
    {
        return 1;
    }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = value;

    if (index == 0)
    {
        new_node->next = ll->head;
        ll->head = new_node;
        if (ll->tail == null) { ll->tail = new_node; }
        return 0;
    }

    if (index == size)
    {
        ll->tail->next = new_node;
        ll->tail = new_node;
        return 0;
    }

    unsigned int in;
    node_s* cur;
    for (in = 0, cur = ll->head; in < index - 1; ++in, cur = cur->next);

    node_s* next = cur->next;
    cur->next = new_node;
    new_node->next = next;
    return 0;
}

int ll_remove(linked_list_s* ll, unsigned int index, int* err_code)
{
    unsigned int size = (unsigned)LIST.size(ll);
    if (LIST.is_empty(ll) == -1 || index >= size)
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }

    if (index == 0)
    {
        node_s* first = ll->head;
        node_s* next = ll->head->next;
        ll->head = next;
        if (next == null) { ll->tail = next; }

        int ret = first->data;
        MEMORY.release(first);

        cond_assign_nn(err_code, 0);
        return ret;
    }

    unsigned int in;
    node_s* cur;
    for (in = 0, cur = ll->head; in < index - 1; ++in, cur = cur->next)
    {
        
    }

    node_s* next = cur->next;
    node_s* nnext = cur->next->next;
    if (nnext == null)
    {
        ll->tail = cur;
    }
    
    int ret = next->data;
    cur->next = nnext;

    MEMORY.release(next);

    cond_assign_nn(err_code, 0);
    return ret;
}

void ll_clear(linked_list_s* ll)
{
    if (ll == null || LIST.is_empty(ll)) { return; }
    while (!LIST.is_empty(ll)) { LIST.pop_back(ll, null); }
}

void ll_display(const linked_list_s* ll)
{
    if (LIST.is_empty(ll)) { return; }
    for (node_s* n = ll->head; n != null; n = n->next) { printf("%d ", n->data); }
    print_n();
}