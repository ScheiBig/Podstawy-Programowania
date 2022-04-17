#include "functions.h"
#include <stdbool.h>
#include "my_utils_v2.h"
#include <limits.h>

int all_even(int number)
{
    if (number == 0)
    {
        return true;
    }
    else if (number % 2 == 1 || number % 2 == -1)
    {
        return false;
    }
    else
    {
        return all_even(number / 10);
    }
}

int all_odd(int number)
{
    static bool started = false;
    if (started && number == 0)
    {
        started = false;
        return true;
    }
    else if (!started && number == 0)
    {
        started = false;
        return false;
    }
    else if (number % 2 == 0)
    {
        started = false;
        return false;
    }
    else
    {
        started = true;
        return all_odd(number / 10);
    }
}

int get_next_number(const int* tab, int size, enum type t)
{
    if (t != ALL_ODD && t != ALL_EVEN && t != MIX)
    {
        return -2;
    }
    static const int* last_tab_s;
    static int last_size_s;
    static int curr_index_s = 0;
    if (tab != null)
    {
        last_tab_s = tab;
        last_size_s = size;
        curr_index_s = 0;
    }
    if (last_tab_s == null || last_size_s <= 0)
    {
        return -2;
    }
    if (curr_index_s == last_size_s)
    {
        return -1;
    }
    int cur_num = *(last_tab_s + curr_index_s);
    ++curr_index_s;
    switch (t)
    {
    case ALL_ODD:
        if (all_odd(cur_num))
        {
            return cur_num;
        }
        else
        {
            return get_next_number(null, size, t);
        }
    case ALL_EVEN:
        if (all_even(cur_num))
        {
            return cur_num;
        }
        else
        {
            return get_next_number(null, size, t);
        }
    case MIX:
        if (!all_even(cur_num) && !all_odd(cur_num))
        {
            return cur_num;
        }
        else
        {
            return get_next_number(null, size, t);
        }
    default:
        return -2;
    }
}

