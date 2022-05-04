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
    if (fscanf(file, "%3s", img->type) != 1)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        free(img);
        return null;
    }
    discard_stream(file);
    int temp;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(file, "%d", &temp) != 1 || 0 > temp || temp > 255)
    {
        cond_assign_nn(err_code, 3);
        fclose(file);
        free(img);
        return null;
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(file, "%d %d", &img->width, &img->height) != 2 || img->width <= 0 || img->height <= 0)
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
            if (fscanf(file, "%d ", (*(img->ptr + y) + x)) <= 0)
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