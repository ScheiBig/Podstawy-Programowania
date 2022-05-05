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
    int y;
    int** arr_2d = (int**)malloc((unsigned)height * sizeof(int*));
    if (arr_2d == null)
    {
        return null;
    }
    for (y = 0; y < height; ++y)
    {
        *(arr_2d + y) = (int*)malloc((unsigned)width * sizeof(int));
        if (*(arr_2d + y) == null)
        {
            for (int i = 0; i < y; ++i)
            {
                free(*(arr_2d + i));
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
    for (int y = 0; y < height; ++y)
    {
        if (*(ptr + y) == null)
        {
            return;
        }
    }
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            printf("%d ", *(*(ptr + y) + x));
        }
        print_n();
    }
}

void __destroy_array_2d(int** ptr, int height)
{
    if (ptr != null && height > 0)
    {
        for (int y = 0; y < height; ++y)
        {
            if (*(ptr + y) != null)
            {
                free(*(ptr + y));
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

void matrix_destroy(struct matrix_t* m)
{
    if (m != null && m->ptr != null && m->width > 0 && m->height > 0)
    {
        __destroy_array_2d(m->ptr, m->height);
    }
}


struct matrix_t* matrix_copy(const struct matrix_t* copy)
{
    if (copy == null || copy->ptr == null || copy->width <= 0 || copy->height <= 0)
    {
        return null;
    }
    struct matrix_t* new_copy = matrix_create_struct(copy->width, copy->height);
    if (new_copy == null)
    {
        return null;
    }
    for (int y = 0; y < copy->height; ++y)
    {
        for (int x = 0; x < copy->width; ++x)
        {
            *(*(new_copy->ptr + y) + x) = *(*(copy->ptr + y) + x);
        }
    }
    return new_copy;
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


struct matrix_t* matrix_add(const struct matrix_t* m1, const struct matrix_t* m2)
{
    if (m1 == null || m1->ptr == null || m1->width <= 0 || m1->height <= 0 ||
        m2 == null || m2->ptr == null || m2->width != m1->width || m2->height != m1->height)
    {
        return null;
    }
    struct matrix_t* result;
    if ((result = matrix_create_struct(m1->width, m1->height)) == null)
    {
        return null;
    }
    for (int y = 0; y < result->height; ++y)
    {
        for (int x = 0; x < result->width; ++x)
        {
            *(*(result->ptr + y) + x) = *(*(m1->ptr + y) + x) + *(*(m2->ptr + y) + x);
        }
    }
    return result;
}

struct matrix_t* matrix_subtract(const struct matrix_t* m1, const struct matrix_t* m2)
{
    if (m1 == null || m1->ptr == null || m1->width <= 0 || m1->height <= 0 ||
        m2 == null || m2->ptr == null || m2->width != m1->width || m2->height != m1->height)
    {
        return null;
    }
    struct matrix_t* result;
    if ((result = matrix_create_struct(m1->width, m1->height)) == null)
    {
        return null;
    }
    for (int y = 0; y < result->height; ++y)
    {
        for (int x = 0; x < result->width; ++x)
        {
            *(*(result->ptr + y) + x) = *(*(m1->ptr + y) + x) - *(*(m2->ptr + y) + x);
        }
    }
    return result;
}

struct  matrix_t* matrix_multiply(const struct matrix_t* m1, const struct matrix_t* m2)
{
    if (m1 == null || m1->ptr == null || m1->width <= 0 || m1->height <= 0 ||
        m2 == null || m2->ptr == null || m1->width != m2->height || m2->height <= 0)
    {
        return null;
    }
    struct matrix_t* result;
    if ((result = matrix_create_struct(m2->width, m1->height)) == null)
    {
        return null;
    }
    for (int y = 0; y < result->height; ++y)
    {
        for (int x = 0; x < result->width; ++x)
        {
            *(*(result->ptr + y) + x) = 0;
            for (int i = 0; i < m2->height; ++i)
            {
                *(*(result->ptr + y) + x) += *(*(m1->ptr + y) + i) * *(*(m2->ptr + i) + x);
            }
        }
    }
    return result;
}


int matrix_read(struct matrix_t* m)
{
    if (m == null || m->ptr == null || m->width <= 0 || m->height <= 0)
    {
        return 1;
    }
    print_ln("Enter numbers:");
    for (int y = 0; y < m->height; ++y)
    {
        for (int x = 0; x < m->width; ++x)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", *(m->ptr + y) + x) != 1)
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

struct matrix_t* matrix_load_b(const char* filename, int* err_code)
{
    if (filename == null || strlen(filename) == 0)
    {
        cond_assign_nn(err_code, 1);
        return null;
    }
    int width;
    int height;
    p_file file;
    if ((file = fopen(filename, "rb")) == null)
    {
        cond_assign_nn(err_code, 2);
        return null;
    }

    if (fread(&width, sizeof(int), 1, file) != 1u || fread(&height, sizeof(int), 1, file) != 1u)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        return null;
    }
    if (width <= 0 || height <= 0)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        return null;
    }
    struct matrix_t* m;
    if ((m = matrix_create_struct(width, height)) == null)
    {
        cond_assign_nn(err_code, 4);
        fclose(file);
        return null;
    }

    for (int y = 0; y < m->height; ++y)
    {
        if ((signed)fread(*(m->ptr + y), sizeof(int), m->width, file) != m->width)
        {
            cond_assign_nn(err_code, 3);
            fclose(file);
            matrix_destroy_struct(&m);
            return null;
        }
    }

    cond_assign_nn(err_code, 0);
    fclose(file);
    return m;
}

struct matrix_t* matrix_load_t(const char* filename, int* err_code)
{
    if (filename == null || strlen(filename) == 0)
    {
        cond_assign_nn(err_code, 1);
        return null;
    }
    int width;
    int height;
    p_file file;
    if ((file = fopen(filename, "rb")) == null)
    {
        cond_assign_nn(err_code, 2);
        return null;
    }

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(file, "%d %d", &width, &height) != 2)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        return null;
    }
    if (width <= 0 || height <= 0)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        return null;
    }
    struct matrix_t* m;
    if ((m = matrix_create_struct(width, height)) == null)
    {
        cond_assign_nn(err_code, 4);
        fclose(file);
        return null;
    }

    for (int y = 0; y < m->height; ++y)
    {
        for (int x = 0; x < m->width; ++x)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (fscanf(file, "%d ", (*(m->ptr + y) + x)) != 1)
            {
                cond_assign_nn(err_code, 3);
                fclose(file);
                matrix_destroy_struct(&m);;
                return null;
            }
        }
        fprintf(file, "\n");
    }

    cond_assign_nn(err_code, 0);
    fclose(file);
    return m;
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
