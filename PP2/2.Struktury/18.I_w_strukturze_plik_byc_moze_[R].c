#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()

struct file_t
{
    FILE* f;
    int size;
};

int open_file(struct file_t* f, const char* filename);
struct file_t* find_min(const struct file_t* files, int size);
void close_file(struct file_t* f);

int main()
{
    struct file_t files[5], * cur_file;
    int file_no = 0;
    char f_buffer[31], t_buffer[1000];
    size_t b_l, t_l;
    print_ln("Enter file paths: ");
    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        fgets(f_buffer, 31, stdin);
        b_l = strlen(f_buffer);
        if (*(f_buffer + b_l - 1) == '\n')
        {
            *(f_buffer + --b_l) = '\0';
        }
        else
        {
            discard_stdin();
        }
        if (b_l == 0)
        {
            break;
        }
        if (open_file(files + file_no, f_buffer) != 0)
        {
            continue;
        }
        if ((files + file_no)->size == 0)
        {
            continue;
        }
        else
        {
            ++file_no;
        }
        if (file_no >= 5)
        {
            continue;
        }
    }
    if (file_no == 0)
    {
        __m_exit(eFILE_noaccess);
    }
    print_ln("Enter your texts: ");
    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        fgets(t_buffer, 1000, stdin);
        t_l = strlen(t_buffer);
        if (*(t_buffer + t_l - 1) == '\n')
        {
            *(t_buffer + --t_l) = '\0';
        }
        else
        {
            discard_stdin();
        }
        if (t_l == 0)
        {
            break;
        }
        cur_file = find_min(files, file_no);
        fprintf(cur_file->f, "%s\n", t_buffer);
        cur_file->size = ftell(cur_file->f);
    }

    for (struct file_t* s = files; s < files + file_no; ++s)
    {
        close_file(s);
    }
    print_ln("Files saved");

    return 0;
}

int open_file(struct file_t* f, const char* filename)
{
    if (f == NULL || filename == NULL || strlen(filename) < 1)
    {
        return 1;
    }
    if ((f->f = fopen(filename, "a")) == NULL)
    {
        return 2;
    }
    f->size = (int)ftell(f->f);
    return 0;
}

struct file_t* find_min(const struct file_t* files, int size)
{
    if (files == NULL || size < 1)
    {
        return NULL;
    }
    const struct file_t* min_f = files;
    for (const struct file_t* s = files + 1; s < files + size; ++s)
    {
        if (min_f->size > s->size)
        {
            min_f = s;
        }
    }
    return (struct file_t*)min_f;
}

void close_file(struct file_t* f)
{
    if (f != NULL)
    {
        if (f->f != NULL)
        {
            fclose(f->f);
        }
    }
}
