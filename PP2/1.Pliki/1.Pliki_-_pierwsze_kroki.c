#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "my_utils.h"

// FILE* files[255];
FILE* files;
// int files_cnt = 0;

void close_files()
{
    // for (FILE** f = files; f < files + files_cnt; ++f)
    // {
        // fclose(*f);
    // }
    if (files != NULL)
    {
        fclose(files);
        files = NULL;
    }
}

FILE* register_file(FILE* file)
{
    if (file == NULL) return NULL;
    // files[files_cnt++] = file;
    files = file;
    return file;
}

int main()
{
    atexit(close_files);
    char buffer[31];
    int c;

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _e_exit(eFILE_noaccess, eFILE_noaccess_msg);
    }

    FILE* file = register_file(fopen(buffer, "r"));

    if (file == NULL)
    {
        _e_exit(eFILE_noaccess, eFILE_noaccess_msg);
    }

    if ((c = fgetc(file)) == EOF)
    {
        print_ln("Nothing to show");
    }
    else
    {
        putc(c, stdout);
        while ((c = fgetc(file)) != EOF)
        {
            putc(c, stdout);
        }
    }

    close_files();
    exit(0);
}
