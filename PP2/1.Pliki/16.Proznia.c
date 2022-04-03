#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
#include "my_exit.h"
#include "my_file.h"

int main()
{
    register_exit_handler(close_file_pointers);
    char buffer[31];

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_noaccess_eno, eFILE_noaccess)
    }

    if (register_file_pointer(fopen(buffer, "r")))
    {
        print_ln("File already exists!");
    }
    else
    {
        if (register_file_pointer(fopen(buffer, "w")))
        {
            print_ln("File created");
        }
        else
        {
            _mh_exit(eFILE_cantcreate_eno, eFILE_cantcreate)
        }
    }

    _h_exit()
}
