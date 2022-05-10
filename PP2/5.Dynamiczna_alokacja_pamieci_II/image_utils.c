#include "image_utils.h"

#include <string.h>
#include <stdlib.h>

#include "my_utils_v2.h"
__include__discard_stream()

struct image_t* load_image_t(c_cstring filename, int* err_code)
{
    if (filename == null || strlen(filename) == 0)
    {
        cond_assign_nn(err_code, 1);
        return null;
    }
    p_file file;
    if ((file = fopen(filename, "r")) == null)
    {
        cond_assign_nn(err_code, 2);
        return null;
    }
    struct image_t* img;
    if ((img = (struct image_t*)malloc(sizeof(struct image_t))) == null)
    {
        cond_assign_nn(err_code, 4);
        fclose(file);
        return null;
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(file, "%3s", img->type) != 1 || strcmp(img->type, "P2"))
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        free(img);
        return null;
    }
    discard_stream(file);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(file, "%d %d", &img->width, &img->height) != 2 || img->width <= 0 || img->height <= 0)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        free(img);
        return null;
    }
    int temp;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(file, "%d", &temp) != 1 || 0 > temp || temp > 255)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        free(img);
        return null;
    }

    if ((img->ptr = (int**)malloc(sizeof(int*) * img->height)) == null)
    {
        cond_assign_nn(err_code, 4);
        fclose(file);
        free(img);
        return null;
    }


    for (int y = 0; y < img->height; ++y)
    {
        if ((*(img->ptr + y) = (int*)malloc(sizeof(int) * img->width)) == null)
        {
            cond_assign_nn(err_code, 4);
            fclose(file);
            for (int i = 0; i < y; ++i)
            {
                free(*(img->ptr + i));
            }
            free(img->ptr);
            free(img);
            return null;
        }
        for (int x = 0; x < img->width; ++x)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (fscanf(file, "%d ", (*(img->ptr + y) + x)) <= 0 ||
                0 > *(*(img->ptr + y) + x) || *(*(img->ptr + y) + x) > 255)
            {
                cond_assign_nn(err_code, 3);
                fclose(file);
                for (int i = 0; i <= y; ++i)
                {
                    free(*(img->ptr + i));
                }
                free(img->ptr);
                free(img);
                return null;
            }
        }
    }

    cond_assign_nn(err_code, 0);
    fclose(file);
    return img;
}

int save_image_t(c_cstring filename, const struct image_t* m1)
{
    if (filename == null || strlen(filename) == 0 || m1 == null ||
        m1->ptr == null || m1->width <= 0 || m1->height <= 0)
    {
        return 1;
    }
    p_file file;
    if ((file = fopen(filename, "w")) == null)
    {
        return 2;
    }
    if (fprintf(file, "%s\n", m1->type) <= 0)
    {
        fclose(file);
        return 3;
    }
    if (fprintf(file, "%d %d\n", m1->width, m1->height) <= 0)
    {
        fclose(file);
        return 3;
    }
    if (fprintf(file, "255\n") <= 0)
    {
        fclose(file);
        return 3;
    }
    for (int y = 0; y < m1->height; ++y)
    {
        for (int x = 0; x < m1->width; ++x)
        {
            if (fprintf(file, "%d ", *(*(m1->ptr + y) + x)) <= 0)
            {
                fclose(file);
                return 3;
            }
        }
        if (fprintf(file, "\n") <= 0)
        {
            fclose(file);
            return 3;
        }
    }

    fclose(file);
    return 0;
}

void destroy_image(struct image_t** m)
{
    if (m != null && (*m) != null)
    {
        if ((*m)->ptr != null && (*m)->width > 0 && (*m)->height > 0)
        {
            for (int y = 0; y < (*m)->height; ++y)
            {
                if (*((*m)->ptr + y) != null)
                {
                    free(*((*m)->ptr + y));
                }
                else
                {
                    return;
                }
            }
            free((*m)->ptr);
        }
        else
        {
            return;
        }
        free((*m));
        (*m) = null;
    }
}

const int* image_get_pixel(const struct image_t* img, int x, int y)
{
    return (const int*)image_set_pixel((struct image_t*)img, x, y);
}


int* image_set_pixel(struct image_t* img, int x, int y)
{
    if (img == null || img->ptr == null || *(img->ptr + y) == null || img->width <= 0 ||
        img->height <= 0 || 0 > x || x >= img->width || 0 > y || y >= img->height)
    {
        return null;
    }
    return (*(img->ptr + y) + x);
}

int draw_image(struct image_t* img, const struct image_t* src, int destx, int desty)
{
    if (image_get_pixel(img, 0, 0) == null || image_get_pixel(src, 0, 0) == null ||
        destx < 0 || desty < 0 || !is_in_range(0, img->width, 0, src->width, destx) ||
        !is_in_range(0, img->height, 0, src->height, desty))
    {
        return 1;
    }
    for (int y = 0; y < src->height; ++y)
    {
        if (*(img->ptr + y + desty) == null || *(src->ptr + y) == null)
        {
            return 1;
        }
        for (int x = 0; x < src->width; ++x)
        {
            *image_set_pixel(img, x + destx, y + desty) = *image_get_pixel(src, x, y);
        }
    }
    return 0;
}
