#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define __discard_stdin__
#include "my_utils.h"
#include "my_exit.h"
#include "my_file.h"

int main()
{
    register_exit_handler(close_file_pointers);
    char buffer[31];

    print_ln("Enter output file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }
    discard_stdin();

    FILE* out_file = register_file_pointer(fopen(buffer, "w"));
    if (out_file == NULL)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }

    for (int i = 0; i <= 100; ++i)
    {
        fprintf(out_file, "%d\n", i);
    }
    
    print_ln("File saved");
    _h_exit()
}
