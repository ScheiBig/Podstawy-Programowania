#include "selection_sort.h"
#include "vector_utils.h"
#include "my_utils.h"

REGISTER_SWAP(int)

int selection_sort_rec(int tab[], int size, enum direction dir)
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
    case ASCENDING: ret = selection_sort_asc_rec(tab, size, 0); break;
    case DESCENDING: ret = selection_sort_desc_rec(tab, size, 0); break;
    }
    // display_vector(tab, size);
    return ret;
}

int ssr_asc_loop(int tab[], int size, int cur)
{
    if (cur >= size - 1) return cur;
    if (cur + 1 == size - 1)
    {
        return (tab[cur] < tab[cur + 1]) ? cur : cur + 1;
    }
    int nextCur = ssr_asc_loop(tab, size, cur + 1);
    return tab[cur] < tab[nextCur] ? cur : nextCur;
}

int selection_sort_asc_rec(int tab[], int size, int index)
{
    if (size < 1) return 1;
    if (index < 0) return 1;
    if (index >= size) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int min = ssr_asc_loop(tab, size, index);
    swap_int(tab + index, tab + min);
    display_vector(tab, size);
    return index + 1 < size ? selection_sort_asc_rec(tab, size, index + 1) : 0;
}

int ssr_desc_loop(int tab[], int size, int cur)
{
    if (cur >= size - 1) return cur;
    if (cur + 1 == size - 1)
    {
        return (tab[cur] > tab[cur + 1]) ? cur : cur + 1;
    }
    int nextCur = ssr_desc_loop(tab, size, cur + 1);
    return tab[cur] > tab[nextCur] ? cur : nextCur;
}

int selection_sort_desc_rec(int tab[], int size, int index)
{
    if (size < 1) return 1;
    if (index < 0) return 1;
    if (index >= size) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int max = ssr_desc_loop(tab, size, index);
    swap_int(tab + index, tab + max);
    display_vector(tab, size);
    return index + 1 < size ? selection_sort_desc_rec(tab, size, index + 1) : 0;
}
