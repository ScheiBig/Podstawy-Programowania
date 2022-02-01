#include "bubble_sort.h"
#include "vector_utils.h"
#include "my_utils.h"

REGISTER_SWAP(int)

int bubble_sort_rec(int tab[], int size, enum direction dir)
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
    case ASCENDING: ret = bubble_sort_asc_rec(tab, size); break;
    case DESCENDING: ret = bubble_sort_desc_rec(tab, size); break;
    }
    display_vector(tab, size);
    return ret;
}

int bsr_asc_loop(int tab[], int size, int cur)
{
    if (cur >= size - 1) return 0;
    int mov = 0;
    if (tab[cur] > tab[cur + 1])
    {
        swap_int(tab + cur, tab + (cur + 1));
        ++mov;
    }
    return mov + bsr_asc_loop(tab, size, cur + 1);
}

int bubble_sort_asc_rec(int tab[], int size)
{

    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int mov = bsr_asc_loop(tab, size, 0);
    if (mov == 0) return 0;
    display_vector(tab, size);
    return bubble_sort_asc_rec(tab, size - 1);
}

int bsr_desc_loop(int tab[], int size, int cur)
{
    if (cur >= size - 1) return 0;
    int mov = 0;
    if (tab[cur] < tab[cur + 1])
    {
        swap_int(tab + cur, tab + (cur + 1));
        ++mov;
    }
    return mov + bsr_desc_loop(tab, size, cur + 1);
}

int bubble_sort_desc_rec(int tab[], int size)
{

    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int mov = bsr_desc_loop(tab, size, 0);
    if (mov == 0) return 0;
    display_vector(tab, size);
    return bubble_sort_desc_rec(tab, size - 1);
}
