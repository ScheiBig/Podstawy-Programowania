#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define __discard_stdin__
#include "my_utils.h"
#include "my_exit.h"
#include "my_file.h"

void filecpy(FILE* in, FILE* out);

int main()
{
    register_exit_handler(close_file_pointers);
    char buffer[31];

    print_ln("Enter input file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    discard_stdin();

    FILE* in_file = register_file_pointer(fopen(buffer, "r"));
    if (in_file == NULL)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }

    print_ln("Enter output file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }

    FILE* out_file = register_file_pointer(fopen(buffer, "w"));
    if (out_file == NULL)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }

    filecpy(in_file, out_file);

    print_ln("File copied");
    _h_exit()
}

void filecpy(FILE* in, FILE* out)
{
    int c;
    while ((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }
}
