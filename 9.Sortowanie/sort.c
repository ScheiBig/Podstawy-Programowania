#include "sort.h"
#include "vector_utils.h"
#include "my_utils.h"
#include <stdio.h>

REGISTER_SWAP(int)

int bubble_sort(int tab[], int size, enum direction dir)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    switch ((int)dir) // Great idea to use two different static checkers - GCC want exhaustive switch, clang thinks default is unreachable
    {
    case ASCENDING: return bubble_sort_asc(tab, size);
    case DESCENDING: return bubble_sort_desc(tab, size);
    }
    return 1;
}

int bubble_sort_asc(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int mov;
    for (int i = size; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (tab[j] > tab[j + 1])
            {
                swap_int(tab + j, tab + i);
                ++mov;
            }
        }
        display_vector(tab, size);
        if (mov == 0) break;
    }
    return 0;
}

int bubble_sort_desc(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int mov;
    for (int i = size; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (tab[j] < tab[j + 1])
            {
                swap_int(tab + j, tab + i);
                ++mov;
            }
        }
        display_vector(tab, size);
        if (mov == 0) break;
    }
    return 0;
}

int selection_sort(int tab[], int size, enum direction dir)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    switch ((int)dir) // Great idea to use two different static checkers - GCC want exhaustive switch, clang thinks default is unreachable
    {
    case ASCENDING: return selection_sort_asc(tab, size);
    case DESCENDING: return selection_sort_desc(tab, size);
    }
    return 1;
}

int selection_sort_asc(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int min;
    for (int i = 0; i < size; ++i)
    {
        min = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (tab[j] < tab[min])
            {
                min = j;
            }
        }
        swap_int(tab + i, tab + min);
        display_vector(tab, size);
    }
    return 0;
}

int selection_sort_desc(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int max;
    for (int i = 0; i < size; ++i)
    {
        max = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (tab[j] > tab[max])
            {
                max = j;
            }
        }
        swap_int(tab + i, tab + max);
        display_vector(tab, size);
    }
    return 0;
}

int insertion_sort(int tab[], int size, enum direction dir)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    switch ((int)dir) // Great idea to use two different static checkers - GCC want exhaustive switch, clang thinks default is unreachable
    {
    case ASCENDING: return insertion_sort_asc(tab, size);
    case DESCENDING: return insertion_sort_desc(tab, size);
    }
    return 1;
}

int insertion_sort_asc(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int curr, j;
    for (int i = 1; i < size; ++i)
    {
        curr = tab[i];
        for (j = i - 1; j >= 0 && tab[j] > curr; --j)
        {
            tab[j + 1] = tab[j];
        }
        tab[j + 1] = curr;
        display_vector(tab, size);
    }
    display_vector(tab, size);
    return 0;
}

int insertion_sort_desc(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int curr, j;
    for (int i = 1; i < size; ++i)
    {
        curr = tab[i];
        for (j = i - 1; j >= 0 && tab[j] < curr; --j)
        {
            tab[j + 1] = tab[j];
        }
        tab[j + 1] = curr;
        display_vector(tab, size);
    }
    display_vector(tab, size);
    return 0;
}
