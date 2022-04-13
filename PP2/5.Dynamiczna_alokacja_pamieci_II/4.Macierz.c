#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

struct matrix_t
{
    int** ptr;
    int width;
    int height;
};


int matrix_create(struct matrix_t* m, int width, int height);
int matrix_read(struct matrix_t* m);
void matrix_display(const struct matrix_t* m);
void matrix_destroy(struct matrix_t* m);

int** __create_array_2d(int width, int height);
void __display_array_2d(int** ptr, int width, int height);
void __destroy_array_2d(int** ptr, int height);

int main()
{

    int w, h;
    print_ln("Enter matrix dimensions:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d %d", &w, &h) != 2)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (w <= 0 || h <= 0)
    {
        __m_exit(eDATA_invalid);
    }

    struct matrix_t mat;

    if (matrix_create(&mat, w, h) != 0)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    if (matrix_read(&mat) != 0)
    {
        matrix_destroy(&mat);
        __m_exit(eINPUT_invalid);
    }
    matrix_display(&mat);
    matrix_destroy(&mat);
    return 0;
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

int matrix_create(struct matrix_t* m, int width, int height)
{
    if (m == null || width <= 0 || height <= 0)
    {
        return 1;
    }
    m->ptr = __create_array_2d(width, height);
    if (m->ptr == null)
    {
        return 2;
    }
    m->width = width;
    m->height = height;
    return 0;
}

int matrix_read(struct matrix_t* m)
{
    if (m == null || m->ptr == null || m->width <= 0 || m->height <= 0)
    {
        return 1;
    }
    print_ln("Enter numbers:");
    for (int i = 0; i < m->height; ++i)
    {
        for (int j = 0; j < m->width; ++j)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", *(m->ptr + i) + j) != 1)
            {
                return 2;
            }
        }

    }
    return 0;
}

void matrix_display(const struct matrix_t* m)
{
    if (m != null && m->ptr != null && m->width > 0 && m->height > 0)
    {
        __display_array_2d(m->ptr, m->width, m->height);
    }
}

void matrix_destroy(struct matrix_t* m)
{
    if (m != null && m->ptr != null && m->width > 0 && m->height > 0)
    {
        __destroy_array_2d(m->ptr, m->height);
    }
}
