#include "vector.h"
#include "my_utils_v2.h"
#include <stdlib.h>

int vector_create_struct(struct vector_t** a, int N)
{
    if (a == null || N < 1)
    {
        return 1;
    }
    if ((*a = (struct vector_t*)calloc(1u, sizeof(struct vector_t))) == null)
    {
        return 2;
    }

    int ret = vector_create(*a, N);
    if (ret != 0)
    {
        free(*a);
    }
    return ret;
}

void vector_destroy_struct(struct vector_t** a)
{
    if (a != null)
    {
        vector_destroy(*a);
        free(*a);
    }
}

int vector_create(struct vector_t* a, int N)
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
    a->size = 0;
    return 0;
}

void vector_destroy(struct vector_t* a)
{
    if (a != null)
    {
        free(a->ptr);
    }
}

void vector_display(const struct vector_t* a)
{
    if (a != null && a->ptr != null && a->size > 0 && a->capacity >= 1 && a->size <= a->capacity)
    {
        for (int i = 0; i < a->size; ++i)
        {
            printf("%d ", *(a->ptr + i));
        }
        print_n();
    }
}

int vector_push_back(struct vector_t* a, int value)
{
    if (a == null || a->ptr == null || a->size < 0 || a->capacity < 1 || a->size > a->capacity)
    {
        return 1;
    }
    if (a->size == a->capacity)
    {
        int* relocate = (int*)realloc(a->ptr, a->capacity * 2 * sizeof(int));
        if (relocate == null)
        {
            return 2;
        }
        a->ptr = relocate;
        a->capacity *= 2;
    }
    *(a->ptr + (a->size)++) = value;
    return 0;
}
int vector_erase(struct vector_t* a, int value)
{
    if (a == null || a->ptr == null || a->size < 0 || a->capacity < 1 || a->size > a->capacity)
    {
        return -1;
    }
    int count = 0;
    for (int i = a->size - 1; i >= 0; --i)
    {
        if (*(a->ptr + i) == value)
        {
            for (int j = i; j < a->size - 1; ++j)
            {
                *(a->ptr + j) = *(a->ptr + j + 1);
            }
            ++count;
            --a->size;
        }
    }
    int next_capacity = max(a->capacity / 2, 1);
    if (a->size <= next_capacity / 2)
    {
        int* relocate = (int*)realloc(a->ptr, next_capacity * sizeof(int));
        if (relocate != null)
        {
            a->ptr = relocate;
            a->capacity = next_capacity;
        }
    }
    return count;
}
