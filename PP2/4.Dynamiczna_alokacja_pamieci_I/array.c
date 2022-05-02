#include "array.h"
#include "my_utils_v2.h"
#include <stdlib.h>

int array_create(struct array_t* a, int N)
{
    if (a == null || N <= 0)
    {
        return 1;
    }
    a->ptr = (int*)malloc((unsigned)N * sizeof(int));
    if (a->ptr == null)
    {
        return 2;
    }
    a->capacity = N;
    a->size = 0;
    return 0;
}

int array_push_back(struct array_t* a, int value)
{
    if (a == null || a->ptr == null || a->size < 0 || a->capacity <= 0 || a->size > a->capacity)
    {
        return 1;
    }
    if (a->size == a->capacity)
    {
        return 2;
    }
    *(a->ptr + (a->size++)) = value;
    return 0;
}

void array_display(const struct array_t* a)
{
    if (a != null && a->ptr != null && a->size > 0 && a->capacity > 0 && a->size <= a->capacity)
    {
        for (int* s = a->ptr; s < a->ptr + a->size; ++s)
        {
            printf("%d ", *s);
        }
    }
}

void array_destroy(struct array_t* a)
{
    if (a != null && a->ptr != null)
    {
        free(a->ptr);
    }
}
