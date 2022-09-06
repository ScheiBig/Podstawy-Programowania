#include "linked_list2.h"

#include "my_utils_v3.h"

const struct linked_list_i LIST = {
    .create = ll_create,
    .push_back = ll_push_back,
    .push_front = ll_push_front,
    .size = ll_size,
    .is_empty = ll_is_empty,
    .clear = ll_clear,
    .display = ll_display,
    .is_sorted_ascending = ll_is_sorted_ascending,
    .insert_words = ll_insert_words
};

linked_list_s* ll_create()
{
    linked_list_s* list = (linked_list_s*)MEMORY.allocate_empty(1, sizeof(linked_list_s));
    if (list == null) { return null; }
    else { return list; }
}

int ll_push_back(linked_list_s* ll, cstring value)
{
    if (LIST.is_empty(ll) == -1) { return 1; }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = MEMORY.duplicate_string(value);
    if (new_node->data == null)
    {
        MEMORY.release(new_node);
        return 2;
    }

    if (LIST.is_empty(ll)) { ll->head = new_node; }
    else { ll->tail->next = new_node; }

    ll->tail = new_node;
    return 0;
}

int ll_push_front(linked_list_s* ll, cstring value)
{
    if (LIST.is_empty(ll) == -1) { return 1; }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = MEMORY.duplicate_string(value);
    if (new_node->data == null)
    {
        MEMORY.release(new_node);
        return 2;
    }

    if (LIST.is_empty(ll)) { ll->tail = new_node; }
    new_node->next = ll->head;

    ll->head = new_node;
    return 0;
}

void ll_pop_back(linked_list_s* ll, int* err_code)
{
    if (LIST.is_empty(ll)) { return; }

    if (ll->head == ll->tail)
    {
        MEMORY.release(ll->head->data);
        MEMORY.release(ll->head);
        ll->head = ll->tail = null;
        return;
    }

    node_s* last = ll->tail;
    node_s* prev;
    for (prev = ll->head; prev->next != last; prev = prev->next);

    prev->next = null;
    ll->tail = prev;

    MEMORY.release(last->data);
    MEMORY.release(last);
    return;
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

void ll_clear(linked_list_s* ll)
{
    if (ll == null || LIST.is_empty(ll)) { return; }
    while (!LIST.is_empty(ll)) { ll_pop_back(ll, null); }
}

void ll_display(const linked_list_s* ll)
{
    if (LIST.is_empty(ll)) { return; }
    for (node_s* n = ll->head; n != null; n = n->next) { printf("%s ", n->data); }
    print_n();
}

int ll_is_sorted_ascending(const struct linked_list_t* ll)
{
    if (LIST.is_empty(ll)) { return -1; }
    for (node_s* n = ll->head; n->next != null; n = n->next)
    {
        if (n->data == null || n->next->data == null) { return -1; }
        if (strcmp(n->data, n->next->data) > 0) { return 0; }
    }
    return 1;
}

int ll_insert(linked_list_s* ll, unsigned int index, c_cstring value)
{
    unsigned int size = (unsigned)LIST.size(ll);
    if (LIST.is_empty(ll) == -1 || index > size) { return 1; }

    node_s* new_node = (node_s*)MEMORY.allocate_empty(1, sizeof(node_s));
    if (new_node == null) { return 2; }
    new_node->data = MEMORY.duplicate_string(value);
    if (new_node->data == null)
    {
        MEMORY.release(new_node);
        return 2;
    }

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

int ll_insert_words(struct linked_list_t* ll, int N, ...)
{
    if (LIST.is_empty(ll) == -1 || N <= 0 || !LIST.is_sorted_ascending(ll)) { return -1; }
    va_list args;
    va_start(args, N);
    c_cstring str;
    int i;

    for (i = 0; i < N; ++i)
    {
        str = va_arg(args, c_cstring);

        if (LIST.is_empty(ll) || strcmp(str, ll->head->data) < 0)
        {
            if (LIST.push_front(ll, (cstring)str) != 0) { break; };
            continue;
        }

        int in;
        node_s* cur;
        int size = LIST.size(ll);

        for (in = 0, cur = ll->head;
            in < size && strcmp(str, cur->data) > 0;
            ++in, cur = cur->next);
        if (ll_insert(ll, in, str) != 0) { break; }
    }


    va_end(args);

    return i;
}