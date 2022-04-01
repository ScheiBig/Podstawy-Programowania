#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils.h"

typedef union
{
    char character;
    struct
    {
        char other : 7;
        char lbs : 1;
    } bits;
} lsb_u;

int encode(const char* input, char* txt, const char* output);
int decode(const char* filename, char* txt, int size);

int main()
{
    FILE* f = fopen("00181.bmp.txt", "r");
    // FILE* f = fopen("a", "r");

    int num;
    char buf;
    char buf2;

    while (fscanf(f, "%d%c", &num, &buf) > 0)
    {
        if (buf == '\n')
        {
            printf_ln("[%d] [%c]", num, buf);
        }
        buf2 = fgetc(f);
        if (buf2 == '\n')
        {
            printf_ln("[%d] [%c]", num, buf);
        }
        else
        {
            fseek(f, -1L, SEEK_CUR);
        }
    }

    fclose(f);
    return 0;
}

int encode(const char* input, char* txt, const char* output)
{
    return 0;
}

int decode(const char* filename, char* txt, int size)
{
    FILE* file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        return 2;
    }
    fclose(file);
    return 0;
}
