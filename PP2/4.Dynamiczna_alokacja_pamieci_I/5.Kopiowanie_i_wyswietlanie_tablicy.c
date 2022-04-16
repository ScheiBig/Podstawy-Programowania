#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int* create_array_int(int N);
int* copy_array_int(const int* ptr, int N);
void display_array_int(const int* ptr, int N);

int main()
{
    print_ln("Enter initial capacity:");
    int init_capacity;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &init_capacity) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (init_capacity <= 1)
    {
        __m_exit(eDATA_invalid);
    }
    int* nums = create_array_int(init_capacity);
    if (nums == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter numbers:");
    for (int i = 0; i < init_capacity; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", nums+i) != 1)
        {
            free(nums);
            __m_exit(eINPUT_invalid);
        }
    }
    int* cp_nums = copy_array_int(nums, init_capacity);
    if (cp_nums == null)
    {
        free(nums);
        __m_exit(eMEMORY_cantallocate);
    }
    display_array_int(nums, init_capacity);
    print_n();
    display_array_int(cp_nums, init_capacity);

    free(cp_nums);
    free(nums);
    return 0;
}

int* create_array_int(int N)
{
    if (N <= 0)
    {
        return null;

    }
    return (int*)malloc((unsigned)N * sizeof(int));
}

int* copy_array_int(const int* ptr, int N)
{
    if (ptr == null || N <= 0)
    {
        return null;
    }
    int* cp = create_array_int(N);
    if (cp == null)
    {
        return null;
    }
    for (int i = 0; i < N; ++i)
    {
        *(cp + i) = *(ptr + i);
    }
    return cp;
}

void display_array_int(const int* ptr, int N)
{
    if (ptr != null && N > 0)
    {
        for (const int* s = ptr; s < ptr + N; ++s)
        {
            printf("%d ", *s);
        }
    }
}
