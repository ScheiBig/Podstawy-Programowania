#pragma once
#include "my_utils.h"

int sort(int tab[], int size, int (*comp)(int, int));
int quicksort(int from, int to, int tab[], int (*comp)(int, int));
int sort_c(char tab[], int size, int (*comp)(int, int));
int quicksort_c(int from, int to, char tab[], int (*comp)(int, int));

int sort(int tab[], int size, int (*comp)(int, int))
{
    if (size < 1) return 1;
    if (tab == (void*)0) return 1;
    if (size == 1) return 0;
    return quicksort(0, size - 1, tab, comp);
}

int sort_c(char tab[], int size, int (*comp)(int, int))
{
    if (size < 1) return 1;
    if (tab == (void*)0) return 1;
    if (size == 1) return 0;
    return quicksort_c(0, size - 1, tab, comp);
}

REGISTER_SWAP(int)

int quicksort(int from, int to, int tab[], int (*comp)(int, int))
{
    if (from < to)
    {
        int piv_v = tab[to];
        int piv_i = from - 1;
        for (int* v = tab + from; v < tab + to; ++v)
        {
            if (comp(*v, piv_v))
            {
                swap_int(tab + (++piv_i), v);
            }
        }
        swap_int(tab + (++piv_i), tab + to);
        quicksort(from, piv_i - 1, tab, comp);
        quicksort(piv_i + 1, to, tab, comp);
    }
    return 0;
}

REGISTER_SWAP(char)

int quicksort_c(int from, int to, char tab[], int (*comp)(int, int))
{
    if (from < to)
    {
        int piv_v = tab[to];
        int piv_i = from - 1;
        for (char* v = tab + from; v < tab + to; ++v)
        {
            if (comp(*v, piv_v))
            {
                swap_char(tab + (++piv_i), v);
            }
        }
        swap_char(tab + (++piv_i), tab + to);
        quicksort_c(from, piv_i - 1, tab, comp);
        quicksort_c(piv_i + 1, to, tab, comp);
    }
    return 0;
}
