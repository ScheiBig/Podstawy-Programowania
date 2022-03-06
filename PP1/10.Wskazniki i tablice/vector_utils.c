#include "vector_utils.h"

#include <stdio.h>

int read_vector(int* vec, int size, int stop_value)
{
    if (size <= 0) return vuVEC_invalid;
    if (vec == NULL) return vuVEC_invalid;
    int i;
    int temp;
    for (i = 0; i < size; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %d", &temp) != 1)
        {
            return vuDATA_invalid;
        }
        else if (temp == stop_value)
        {
            return i;
        }
        else
        {
            *(vec+i) = temp;
        }
    }
    char trash;
    do
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%c", &trash);
    } while (trash != '\n');

    return i;
}

void display_vector(const int* vec, int size)
{
    if (size <= 0) return;
    if (vec == NULL) return;
    for (const int* v = vec; v < vec + size; ++v)
    {
        printf("%d ", *v);
    }

    printf("\n");
}


void shift_once(int* array, int array_size, enum direction dir);

int shift(int* array, int array_size, int positions_to_shift, enum direction dir)
{
    if (array_size <= 0) return 1;
    if (positions_to_shift < 0) return 1;
    if (array == NULL) return 1;
    switch ((int)dir)
    {
    case ROTATE_RIGHT: case ROTATE_LEFT: {
        if (array_size == 1) return 0;
        for (int i = 0; i < positions_to_shift; ++i)
        {
            shift_once(array, array_size, dir);
        }
        return 0;
    }
    default: return 1;
    }
}

void shift_once(int* array, int array_size, enum direction dir)
{
    switch ((int)dir)
    {
    case ROTATE_RIGHT: {
        int tail = *(array + (array_size - 1));
        for (int* v = (array + (array_size - 1)); v > array; --v)
        {
            *v = *(v - 1);
        }
        *(array) = tail;
        return;
    }
    case ROTATE_LEFT:
    {
        int head = *(array);
        for (int* v = array; v < (array + (array_size - 1)); ++v)
        {
            *v = *(v + 1);
        }
        *(array + (array_size - 1)) = head;
        return;
    }
    }
}
