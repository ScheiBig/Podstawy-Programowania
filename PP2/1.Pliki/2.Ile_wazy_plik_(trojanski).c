#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "my_utils.h"
#include "my_exit.h"
#include "my_file.h"

int file_size_from_path(const char* path);
int file_size_from_file(FILE* f);

int main()
{
    register_exit_handler(close_file_pointers);
    char buffer[31];

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }

    int s1 = file_size_from_path(buffer);
    FILE* file = register_file_pointer(fopen(buffer, "r"));
    int s2 = file_size_from_file(file);

    if (s1 == s2)
    {
        printf_ln("File size is %d", s1);
    }
    else if (s1 < 0 || s2 < 0 || file == NULL)
    {
        _m_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    else
    {
        print_ln("Error");
    }
    _h_exit()
}

int file_size_from_path(const char* path)
{
    if (path == NULL) return -2;
    FILE* f = fopen(path, "r");
    if (f == NULL) return -1;
    int size = 0;
    while (fgetc(f) != EOF) ++size;
    fclose(f);
    return size;
}

int file_size_from_file(FILE* f)
{
    if (f == NULL) return -2;
    long startPos = ftell(f);
    fseek(f, 0L, SEEK_END);
    int size = (int)ftell(f);
    fseek(f, startPos, SEEK_SET);
    return size;
}
