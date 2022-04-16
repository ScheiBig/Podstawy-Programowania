#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int create_array_2d_2(int*** ptr, int width, int height);
void destroy_array_2d(int*** ptr, int height);
void display_array_2d(int** ptr, int width, int height);
int sum_array_2d(int** ptr, int width, int height);
int sum_row(int* ptr, int width);

int** __create_array_2d(int width, int height);
void __display_array_2d(int** ptr, int width, int height);
void __destroy_array_2d(int** ptr, int height);

int main()
{
    int w, h;
    print_ln("Enter array dimensions:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d %d", &w, &h) != 2)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (w <= 0 || h <= 0)
    {
        __m_exit(eDATA_invalid);
    }

    int** arr;
    
    if (create_array_2d_2(&arr, w, h) != 0)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter numbers:");
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", *(arr + i) + j) != 1)
            {
                destroy_array_2d(&arr, h);
                __m_exit(eINPUT_invalid);
            }
        }

    }
    display_array_2d(arr, w, h);
    for (int** s = arr; s < arr + h; ++s)
    {
        printf_ln("%d", sum_row(*(s), w));
    }
    printf_ln("%d", sum_array_2d(arr, w, h));

    destroy_array_2d(&arr, h);

    return 0;
}


int create_array_2d_2(int*** ptr, int width, int height)
{
    if (ptr == null || width <= 0 || height <= 0)
    {
        return 1;
    }
    *(ptr) = __create_array_2d(width, height);
    if (*(ptr) == null)
    {
        return 2;
    }
    return 0;
}

void destroy_array_2d(int*** ptr, int height)
{
    if (ptr != null && height > 0)
    {
        __destroy_array_2d(*(ptr), height);
        *(ptr) = null;
    }
}

void display_array_2d(int** ptr, int width, int height)
{
    __display_array_2d(ptr, width, height);
}

int sum_array_2d(int** ptr, int width, int height)
{
    if (ptr == null || width <= 0 || height <= 0)
    {
        return -1;
    }
    int ret = 0;
    for (int** s = ptr; s < ptr + height; ++s)
    {
        if (*(ptr) == null)
        {
            return -1;
        }
        ret += sum_row(*(s), width);
    }
    return ret;
}

int sum_row(int* ptr, int width)
{
    if (ptr == null || width <= 0)
    {
        return -1;
    }
    int ret = 0;
    for (int* s = ptr; s < ptr + width; ++s)
    {
        ret += *(s);
    }
    return ret;
}

int** __create_array_2d(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        return null;
    }
    int i;
    int** arr_2d = (int**)malloc((unsigned)height * sizeof(int*));
    if (arr_2d == null)
    {
        return null;
    }
    for (i = 0; i < height; ++i)
    {
        *(arr_2d + i) = (int*)malloc((unsigned)width * sizeof(int));
        if (*(arr_2d + i) == null)
        {
            for (int j = 0; j < i; ++j)
            {
                free(*(arr_2d + j));
            }
            free(arr_2d);
            return null;
        }
    }
    return arr_2d;
}

void __display_array_2d(int** ptr, int width, int height)
{
    if (ptr == null || width <= 0 || height <= 0)
    {
        return;
    }
    for (int i = 0; i < height; ++i)
    {
        if (*(ptr + i) == null)
        {
            return;
        }
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            printf("%d ", *(*(ptr + i) + j));
        }
        print_n();
    }
}

void __destroy_array_2d(int** ptr, int height)
{
    if (ptr != null && height > 0)
    {
        for (int i = 0; i < height; ++i)
        {
            if (*(ptr + i) != null)
            {
                free(*(ptr + i));
            }
        }
        free(ptr);
    }
}

// "workspace.c"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <math.h>
// #include <time.h>

// #include "my_utils_v2.h"
// #include "tested_declarations.h"
// #include "rdebug.h"

// int** create_array_2d(int width, int height);
// void display_array_2d(int** ptr, int width, int height);
// void destroy_array_2d(int** ptr, int height);

// int main()
// {
//     int w, h;
//     print_ln("Enter array dimensions:");
//     //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
//     if (scanf("%d %d", &w, &h) != 2)
//     {
//         __m_exit(eINPUT_invalid);
//     }
//     else if (w <= 0 || h <= 0)
//     {
//         __m_exit(eDATA_invalid);
//     }
//     int** arr = create_array_2d(w, h);
//     if (arr == null)
//     {
//         __m_exit(eMEMORY_cantallocate);
//     }
//     print_ln("Enter numbers:");
//     for (int i = 0; i < h; ++i)
//     {
//         for (int j = 0; j < w; ++j)
//         {
//             //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
//             if (scanf("%d", *(arr + i) + j) != 1)
//             {
//                 destroy_array_2d(arr, h);
//                 __m_exit(eINPUT_invalid);
//             }
//         }

//     }
//     display_array_2d(arr, w, h);
//     destroy_array_2d(arr, h);
//     return 0;
// }

// int** create_array_2d(int width, int height)
// {
//     if (width <= 0 || height <= 0)
//     {
//         return null;
//     }
//     int i;
//     int** arr_2d = (int**)malloc((unsigned)height * sizeof(int*));
//     if (arr_2d == null)
//     {
//         return null;
//     }
//     for (i = 0; i < height; ++i)
//     {
//         *(arr_2d + i) = (int*)malloc((unsigned)width * sizeof(int));
//         if (*(arr_2d + i) == null)
//         {
//             for (int j = 0; j < i; ++j)
//             {
//                 free(*(arr_2d + j));
//             }
//             free(arr_2d);
//             return null;
//         }
//     }
//     return arr_2d;
// }

// void display_array_2d(int** ptr, int width, int height)
// {
//     if (ptr == null || width <= 0 || height <= 0)
//     {
//         return;
//     }
//     for (int i = 0; i < height; ++i)
//     {
//         if (*(ptr + i) == null)
//         {
//             return;
//         }
//     }
//     for (int i = 0; i < height; ++i)
//     {
//         for (int j = 0; j < width; ++j)
//         {
//             printf("%d ", *(*(ptr + i) + j));
//         }
//         print_n();
//     }
// }

// void destroy_array_2d(int** ptr, int height)
// {
//     if (ptr != null && height > 0)
//     {
//         for (int i = 0; i < height; ++i)
//         {
//             if (*(ptr + i) != null)
//             {
//                 free(*(ptr + i));
//             }
//         }
//         free(ptr);
//     }
// }
