#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__string_endswith()

struct point_t
{
    int x;
    int y;
};

struct point_t* set(struct point_t* p, int x, int y);
void show(const struct point_t* p);

int save_point_b(const char* filename, const struct point_t* p);
int load_point_b(const char* filename, struct point_t* p);
int save_point_t(const char* filename, const struct point_t* p);
int load_point_t(const char* filename, struct point_t* p);

int main()
{
    srand(time(NULL));

    struct point_t p1;
    set(&p1, clip_range(rand(), -50, 50), clip_range(rand(), -50, 50));
    show(&p1);
    char buffer[31];
    char answer;

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        __m_exit(eFILE_cantcreate);
    }

    if (string_endswith(buffer, ".bin"))
    {
        if (save_point_b(buffer, &p1) != 0)
        {
            __m_exit(eFILE_cantcreate);
        }
        print_ln("File saved");
        print_ln("Do you want to read the file (Y/N): ");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%*c%c", &answer) != 1)
        {
            __m_exit(eINPUT_invalid);
        }
        if (answer == 'n' || answer == 'N')
        {
            return 0;
        }
        else if (answer == 'y' || answer == 'Y')
        {
            struct point_t p2;
            switch (load_point_b(buffer, &p2))
            {
            case 1: case 3: {
                __m_exit(eFILE_corrupted);
            }
            case 2: {
                __m_exit(eFILE_noaccess);
            }
            default: {
                show(&p2);
                return 0;
            }
            }
        }
        else
        {
            __m_exit(eINPUT_invalid);
        }
    }
    else if (string_endswith(buffer, ".txt"))
    {
        if (save_point_t(buffer, &p1) != 0)
        {
            __m_exit(eFILE_cantcreate);
        }
        print_ln("File saved");
        print_ln("Do you want to read the file (Y/N): ");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%*c%c", &answer) != 1)
        {
            __m_exit(eINPUT_invalid);
        }
        if (answer == 'n' || answer == 'N')
        {
            return 0;
        }
        else if (answer == 'y' || answer == 'Y')
        {
            struct point_t p2;
            switch (load_point_t(buffer, &p2))
            {
            case 1: case 3: {
                __m_exit(eFILE_corrupted);
            }
            case 2: {
                __m_exit(eFILE_noaccess);
            }
            default: {
                show(&p2);
                return 0;
            }
            }
        }
        else
        {
            __m_exit(eINPUT_invalid);
        }
    }
    else
    {
        __m_exit(eFILE_unsupported);
    }
}

struct point_t* set(struct point_t* p, int x, int y)
{
    if (p == NULL)
    {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

void show(const struct point_t* p)
{
    if (p != NULL)
    {
        printf_ln("{ x: %d, y: %d }", p->x, p->y);
    }
}

int save_point_b(const char* filename, const struct point_t* p)
{
    if (filename == NULL || p == NULL)
    {
        return 1;
    }
    FILE* out_file = fopen(filename, "wb");
    if (out_file == NULL)
    {
        return 2;
    }
    if (fwrite(p, sizeof(struct point_t), 1, out_file) == 0)
    {
        fclose(out_file);
        return 3;
    };
    fclose(out_file);
    return 0;
}

int load_point_b(const char* filename, struct point_t* p)
{
    if (filename == NULL || p == NULL)
    {
        return 1;
    }
    FILE* in_file = fopen(filename, "rb");
    if (in_file == NULL)
    {
        return 2;
    }
    if (fread(p, sizeof(struct point_t), 1, in_file) == 0)
    {
        fclose(in_file);
        return 3;
    };
    fclose(in_file);
    return 0;
}

int save_point_t(const char* filename, const struct point_t* p)
{
    if (filename == NULL || p == NULL)
    {
        return 1;
    }
    FILE* out_file = fopen(filename, "w");
    if (out_file == NULL)
    {
        return 2;
    }
    if (fprintf(out_file, "%d %d", p->x, p->y) == 0)
    {
        fclose(out_file);
        return 3;
    };
    fclose(out_file);
    return 0;
}

int load_point_t(const char* filename, struct point_t* p)
{
    if (filename == NULL || p == NULL)
    {
        return 1;
    }
    FILE* in_file = fopen(filename, "r+");
    if (in_file == NULL)
    {
        return 2;
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (fscanf(in_file, "%d %d", &p->x, &p->y) != 2)
    {
        fclose(in_file);
        return 3;
    };
    fclose(in_file);
    return 0;
}
