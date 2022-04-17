#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()
#include "vector_utils.h"

int find(const int* tab, int size, int to_find);

int main()
{
    int nums[100];
    int num_cnt;
    print_ln("Enter an array:");
    switch (num_cnt = read_vector(nums, 100, 0))
    {
    case -2: __m_exit(eINPUT_invalid);
    case 0: __m_exit(eDATA_insufficient);
    }
    discard_stdin();
    int query_num;
    print_ln("Enter a number to find:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &query_num) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    
    int cur_num = find(nums, num_cnt, query_num);
    if (cur_num == -1)
    {
        print_ln("Nothing to show");
    }
    else
    {
        do
        {
            printf("%d ", cur_num);
        } while ((cur_num = find(null, 0, query_num)) != -1);
        print_n();
    }
    
    return 0;
}

int find(const int* tab, int size, int to_find)
{
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
    if (cur_num != to_find)
    {
        return find(null, 0, to_find);
    }
    else
    {
        return curr_index_s - 1;
    }
}
