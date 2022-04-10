#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int create_array_int(int** ptr, int N);
void destroy_array_int(int** ptr);

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
    int* nums;
    if (create_array_int(&nums, init_capacity) == 2)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter numbers:");
    for (int i = 0; i < init_capacity; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", nums+i) != 1)
        {
            destroy_array_int(&nums);
            __m_exit(eINPUT_invalid);
        }
    }

    for (int i = init_capacity - 1; i >= 0; --i)
    {
        printf("%d ", *(nums + i));
    }

    destroy_array_int(&nums);
    return 0;
}

int create_array_int(int** ptr, int N)
{
    if (ptr == null || N <= 0)
    {
        return 1;
    }
    *ptr = (int*)malloc((unsigned)N * sizeof(int));
    if (*ptr == null)
    {
        return 2;
    }
    return 0;
}

void destroy_array_int(int** ptr)
{
    if (ptr != null)
    {
        free(*ptr);
        *ptr = null;
    }
}
