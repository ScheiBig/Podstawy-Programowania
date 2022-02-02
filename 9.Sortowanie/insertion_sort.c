#include "insertion_sort.h"
#include "vector_utils.h"
#include "my_utils.h"

REGISTER_SWAP(int)

int insertion_sort_rec(int tab[], int size, enum direction dir)
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
    case ASCENDING: ret = insertion_sort_asc_rec(tab, size); break;
    case DESCENDING: ret = insertion_sort_desc_rec(tab, size); break;
    }
    display_vector(tab, size);
    return ret;
}

void isr_asc_loop(int tab[], int cur)
{
    if (cur < 1) return;
    if (tab[cur] > tab[cur - 1]) return;
    swap_int(tab+ cur, tab + (cur - 1));
    isr_asc_loop(tab, cur - 1);
}

int insertion_sort_asc_rec(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    if (size == 2)
    {
        int min = min(tab[0], tab[1]);
        int max = max(tab[0], tab[1]);
        tab[0] = min;
        tab[1] = max;
        display_vector(tab, 2);
        return 0;
    }
    int ret = insertion_sort_asc_rec(tab, size - 1);
    isr_asc_loop(tab, size - 1);
    display_vector(tab, size);
    return ret;
}

void isr_desc_loop(int tab[], int cur)
{
    if (cur < 1) return;
    if (tab[cur] < tab[cur - 1]) return;
    swap_int(tab + cur, tab + (cur - 1));
    isr_desc_loop(tab, cur - 1);
}

int insertion_sort_desc_rec(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    if (size == 2)
    {
        int min = min(tab[0], tab[1]);
        int max = max(tab[0], tab[1]);
        tab[0] = max;
        tab[1] = min;
        display_vector(tab, 2);
        return 0;
    }
    int ret = insertion_sort_desc_rec(tab, size - 1);
    isr_desc_loop(tab, size - 1);
    display_vector(tab, size);
    return ret;
}
