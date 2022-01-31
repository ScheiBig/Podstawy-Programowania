#include "sort.h"
#include "vector_utils.h"
#include <stdio.h>

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
    int temp, mov;
    for (int i = size; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
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
    int temp, mov;
    for (int i = size; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (tab[j] < tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                ++mov;
            }
        }
        display_vector(tab, size);
        if (mov == 0) break;
    }
    return 0;
}
