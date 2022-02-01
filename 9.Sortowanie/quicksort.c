#include "quicksort.h"
#include "vector_utils.h"
#include "my_utils.h"
#include <stdio.h>

REGISTER_SWAP(int)

int pivot_asc(int l, int r, int tab[]);
int pivot_desc(int l, int r, int tab[]);

int quicksort(int tab[], int size, enum direction dir)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int ret = 1;
    switch ((int)dir) // Great idea to use two different static checkers - GCC want exhaustive switch, clang thinks default is unreachable
    {
    case ASCENDING: ret = quicksort_asc(0, size - 1, tab, size); break;
    case DESCENDING: ret = quicksort_desc(0, size - 1, tab, size); break;
    }
    display_vector(tab, size);
    return ret;
}

int quicksort_asc(int l, int r, int tab[], int tabSize)
{
    if (tabSize < 1) return 1;
    if (l < 0) return 1;
    if (r < l) return 1;
    if (tabSize < r) return 1;
    if (tabSize == 1)
    {
        display_vector(tab, tabSize);
        return 0;
    }
    if (l < r)
    {
        int i = pivot_asc(l, r, tab);

        quicksort_asc(l, i - 1, tab, tabSize);
        quicksort_asc(i + 1, r, tab, tabSize);
    }
    return 0;
}

int quicksort_desc(int l, int r, int tab[], int tabSize)
{
    if (tabSize < 1) return 1;
    if (l < 0) return 1;
    if (r < l) return 1;
    if (tabSize < r) return 1;
    if (tabSize == 1)
    {
        display_vector(tab, tabSize);
        return 0;
    }
    if (l < r)
    {
        int piv_i = pivot_desc(l, r, tab);

        quicksort_desc(l, piv_i - 1, tab, tabSize);
        quicksort_desc(piv_i + 1, r, tab, tabSize);
    }
    return 0;
}

int pivot_asc(int l, int r, int tab[])
{
    int piv_v = tab[r];
    int piv_i = l - 1;
    for (int* j = tab + l; j < tab + r; ++j)
    {
        if (*j < piv_v)
        {
            swap_int(tab + (++piv_i), j);
        }
    }
    swap_int(tab + (++piv_i), tab + r);
    return piv_i;
}

int pivot_desc(int l, int r, int tab[])
{
    int piv_v = tab[r];
    int piv_i = l - 1;
    for (int* j = tab + l; j < tab + r; ++j)
    {
        if (*j > piv_v)
        {
            swap_int(tab + (++piv_i), j);
        }
    }
    swap_int(tab + (++piv_i), tab + r);
    return piv_i;
}
