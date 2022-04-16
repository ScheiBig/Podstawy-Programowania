#include "circular_buffer.h"
#include "my_utils_v2.h"
#include <stdlib.h>

int circular_buffer_create(struct circular_buffer_t* a, int N)
{
    if (a == null || N < 1)
    {
        return 1;
    }
    a->ptr = (int*)calloc(N, sizeof(int));
    if (a->ptr == NULL)
    {
        return 2;
    }
    a->capacity = N;
    a->begin = a->end = a->full = 0;
    return 0;
}

int circular_buffer_create_struct(struct circular_buffer_t** cb, int N)
{
    if (cb == null || N < 1)
    {
        return 1;
    }
    if ((*cb = (struct circular_buffer_t*)calloc(1u, sizeof(struct circular_buffer_t))) == null)
    {
        return 2;
    }

    int ret = circular_buffer_create(*cb, N);
    if (ret != 0)
    {
        free(*cb);
    }
    return ret;
}

void circular_buffer_destroy(struct circular_buffer_t* a)
{
    if (a != null)
    {
        free(a->ptr);
    }
}

void circular_buffer_destroy_struct(struct circular_buffer_t** a)
{
    if (a != null)
    {
        circular_buffer_destroy(*a);
        free(*a);
    }
}

int circular_buffer_push_back(struct circular_buffer_t* cb, int value)
{
    if (cb == null || cb->ptr == null || cb->capacity < 1 || 0 > cb->begin || cb->begin > cb->capacity || 0 > cb->end || cb->end > cb->capacity)
    {
        return 1;
    }
    *(cb->ptr + cb->end) = value;
    cb->end = (cb->end + 1) % cb->capacity;
    int temp;

    if (cb->full && cb->end == (temp = (cb->begin + 1) % cb->capacity))
    {
        cb->begin = temp;
    }
    else if (!cb->full && cb->end == cb->begin)
    {
        cb->full = 1;
    }
    
    return 0;
}

int circular_buffer_pop_front(struct circular_buffer_t* a, int* err_code)
{
    if (a == null || a->ptr == null || a->capacity < 1 || 0 > a->begin || a->begin > a->capacity || 0 > a->end || a->end > a->capacity)
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }
    if (!a->full && a->begin == a->end)
    {
        cond_assign_nn(err_code, 2);
        return 0;
    }
    int ret = *(a->ptr + a->begin);
    a->begin = (a->begin + 1) % a->capacity;
    a->full = 0;
    cond_assign_nn(err_code, 0);
    return ret;
}

int circular_buffer_pop_back(struct circular_buffer_t* a, int* err_code)
{
    if (a == null || a->ptr == null || a->capacity < 1 || 0 > a->begin || a->begin > a->capacity || 0 > a->end || a->end > a->capacity)
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }
    if (!a->full && a->begin == a->end)
    {
        cond_assign_nn(err_code, 2);
        return 0;
    }
    a->end = (a->end + a->capacity - 1) % a->capacity;
    int ret = *(a->ptr + a->end);
    a->full = 0;
    cond_assign_nn(err_code, 0);
    return ret;
}

int circular_buffer_empty(const struct circular_buffer_t* a)
{
    if (a == null || a->ptr == null || a->capacity < 1 || 0 > a->begin || a->begin > a->capacity || 0 > a->end || a->end > a->capacity)
    {
        return -1;
    }
    return (!a->full) && (a->begin == a->end);
}

int circular_buffer_full(const struct circular_buffer_t* a)
{
    if (a == null || a->ptr == null || a->capacity < 1 || 0 > a->begin || a->begin > a->capacity || 0 > a->end || a->end > a->capacity)
    {
        return -1;
    }
    return a->full;
}

void circular_buffer_display(const struct circular_buffer_t* a)
{
    if (a != null && a->ptr != null && a->capacity > 0 && 0 <= a->begin && a->begin <= a->capacity && 0 <= a->end && a->end <= a->capacity && !circular_buffer_empty(a))
    {
        int i = a->begin;
        do 
        {
            printf("%d ", *(a->ptr + i));
            i = (i + 1) % a->capacity;
        } while ((i % a->capacity) != a->end);
        print_n();
    }
}
