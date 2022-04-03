#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__string_prepend()
#include "my_exit.h"
#include "my_file.h"

int main()
{
    register_exit_handler(close_file_pointers);
    char buffer[51];

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_noaccess_eno, eFILE_noaccess)
    }
    int last = strlen(buffer) - 1;

    if (
        *(buffer + last) != 'p' ||
        *(buffer + last - 1) != 'm' ||
        *(buffer + last - 2) != 'b' ||
        *(buffer + last - 3) != '.'
        )
    {
        _mh_exit(eFILE_unsupported_eno, eFILE_unsupported)
    }

    
    FILE* in_file = register_file_pointer(fopen(buffer, "rb"));
    if (in_file == NULL)
    {
        _mh_exit(eFILE_noaccess_eno, eFILE_noaccess)
    }

    string_prepend(buffer, '_');
    string_prepend(buffer, 'y');
    string_prepend(buffer, 'p');
    string_prepend(buffer, 'o');
    string_prepend(buffer, 'c');

    FILE* out_file = register_file_pointer(fopen(buffer, "wb"));
    if (out_file == NULL)
    {
        _mh_exit(eFILE_cantcreate_eno, eFILE_cantcreate)
    }

    char buf_char = 0;

    while (fread(&buf_char, sizeof(buf_char), 1, in_file))
    {
        fwrite(&buf_char, sizeof(buf_char), 1, out_file);
    }

    print_ln("File saved");
    _h_exit()
}
