#include "matrix_utils.h"

#include <stdlib.h>
#include <string.h>

#include "my_utils_v2.h"


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

struct matrix_t* matrix_create_struct(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        return null;
    }
    struct matrix_t* mt_ptr = (struct matrix_t*)malloc(sizeof(struct matrix_t));
    if (mt_ptr == null)
    {
        return null;
    }
    if (matrix_create(mt_ptr, width, height) != 0)
    {
        free(mt_ptr);
        return null;
    }
    mt_ptr->height = height;
    mt_ptr->width = width;
    return mt_ptr;
}

void matrix_destroy_struct(struct matrix_t** m)
{
    if (m != null)
    {
        matrix_destroy(*(m));
        free(*(m));
        *(m) = null;
    }
}

struct matrix_t* matrix_transpose(const struct matrix_t* m)
{
    if (m == null || m->ptr == null || m->width <= 0 || m->height <= 0)
    {
        return null;
    }
    struct matrix_t* mt_ptr = matrix_create_struct(m->height, m->width);
    if (mt_ptr == null)
    {
        return null;
    }
    for (int y = 0; y < m->height; ++y)
    {
        for (int x = 0; x < m->width; ++x)
        {
            *(*(mt_ptr->ptr + x) + y) = *(*(m->ptr + y) + x);
        }
    }
    return mt_ptr;
}

int matrix_save_b(const struct matrix_t* m, const char* filename)
{
    if (m == null || m->ptr == null || m->width <= 0 || m->height <= 0 ||
        filename == null || strlen(filename) == 0)
    {
        return 1;
    }
    p_file file;
    if ((file = fopen(filename, "wb")) == null)
    {
        return 2;
    }

    if (fwrite(&(m->width), sizeof(int), 2, file) != 2u)
    {
        fclose(file);
        return 3;
    }
    for (int y = 0; y < m->height; ++y)
    {
        if ((signed)fwrite(*(m->ptr + y), sizeof(int), m->width, file) != m->width)
        {
            fclose(file);
            return 3;
        }
    }

    fclose(file);
    return 0;
}

int matrix_save_t(const struct matrix_t* m, const char* filename)
{
    if (m == null || m->ptr == null || m->width <= 0 || m->height <= 0 ||
        filename == null || strlen(filename) == 0)
    {
        return 1;
    }
    p_file file;
    if ((file = fopen(filename, "w")) == null)
    {
        return 2;
    }

    if (fprintf(file, "%d %d\n", m->width, m->height) <= 0)
    {
        fclose(file);
        return 3;
    }
    for (int y = 0; y < m->height; ++y)
    {
        for (int x = 0; x < m->width; ++x)
        {
            if (fprintf(file, "%d ", *(*(m->ptr + y) + x)) <= 0)
            {
                fclose(file);
                return 3;
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
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
