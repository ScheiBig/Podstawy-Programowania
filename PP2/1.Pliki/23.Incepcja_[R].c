#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int read_file(const char* filename);

int main()
{
    char buffer[31];
    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _m_exit(eFILE_noaccess_eno, eFILE_noaccess);
    }
    int file_count = read_file(buffer);
    if (file_count  > 0)
    {
        printf("%d", file_count);
    }
    else
    {
        _m_exit(eFILE_noaccess_eno, eFILE_noaccess);
    }

    return 0;
}

int read_file(const char* filename)
{
    if (filename == NULL)
    {
        return -1;
    }
    char buffer[31];
    u_int file_count = 0;
    FILE* file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        return (signed)file_count;
    }
    u_int buf_last;
    int cur_count;
    while (fgets(buffer, 31, file) != NULL)
    {
        buf_last = strlen(buffer) - 1u;
        if (*(buffer + buf_last) == '\n')
        {
            *(buffer + buf_last) = str_term;
        }
        printf_ln("%s", buffer);
        if ((cur_count = read_file(buffer)) != -1)
        {
            file_count += (unsigned)cur_count;
        }
    }
    fclose(file);
    return (signed)file_count + 1;
}
