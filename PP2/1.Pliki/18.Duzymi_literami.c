#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "my_utils_v2.h"
__include__discard_stdin()
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
        printf("COULDN'T OPEN FILE");
        _nh_exit(eFILE_noaccess_eno)
    }
    discard_stdin();
    FILE* in_file = register_file_pointer(fopen(buffer, "r"));
    if (in_file == NULL)
    {
        printf("COULDN'T OPEN FILE");
        _nh_exit(eFILE_noaccess_eno)
    }

    int buf_char;
    if ((buf_char = fgetc(in_file)) == EOF)
    {
        printf("NOTHING TO SHOW");
    }
    else
    {
        fputc(to_uppercase(buf_char), stdout);
        while ((buf_char = fgetc(in_file)) != EOF)
        {
            fputc(to_uppercase(buf_char), stdout);
        }
    }

    _h_exit()
}
