#include "statistics.h"
#include "my_utils.h"

int quicksort_(int tab[], int size);

float median(int tab[], int size)
{
    if (size < 1) return 0;
    // if null ?
    quicksort_(tab, size);
    if (size % 2 == 0)
    {
        return (float)(tab[size / 2] + tab[size / 2 - 1]) / 2;
    }
    else
    {
        return (float)(tab[size / 2]);
    }
}

float average(const int tab[], int size)
{
    if (size < 1) return 0;
    float sum = 0;
    for (const int* v = tab; v < tab + size; ++v)
    {
        sum += (float)*v;
    }
    return sum / (float)size;
}

int mode(int tab[], int size)
{
    if (size < 1) return 0;
    quicksort_(tab, size);
    int current_count = 1;
    int current_val = tab[0];
    int prev_max_count = 0;
    int prev_max_val = 0;
    for (int* v = tab + 1; v < tab + size; ++v)
    {
        if (*v == current_val)
        {
            ++current_count;
        }
        else
        {
            if (prev_max_count < current_count ||
                (prev_max_count == current_count && prev_max_val > current_val))
            {
                prev_max_count = current_count;
                prev_max_val = current_val;
            }
            current_count = 1;
            current_val = *v;
        }
    }
    if (prev_max_count < current_count ||
        (prev_max_count == current_count && prev_max_val > current_val))
    {
        prev_max_val = current_val;
    }
    return prev_max_val;
}

REGISTER_SWAP(int)

int pivot_asc(int l, int r, int tab[]);
int quicksort_asc(int l, int r, int tab[], int tabSize);

int quicksort_(int tab[], int size)
{
    if (size < 1) return 1;
    if (size == 1)
    {
        return 0;
    }
    return quicksort_asc(0, size - 1, tab, size);
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

int quicksort_asc(int l, int r, int tab[], int tabSize)
{
    if (tabSize < 1) return 1;
    if (l < 0) return 1;
    if (r < l) return 1;
    if (tabSize < r) return 1;
    if (tabSize == 1)
    {
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
