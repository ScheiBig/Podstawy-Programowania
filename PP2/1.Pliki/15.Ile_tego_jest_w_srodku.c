#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define __discard_stdin__
#include "my_utils.h"
#include "my_exit.h"
#include "my_file.h"

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

    FILE* in_file = register_file_pointer(fopen(buffer, "r"));
    if (in_file == NULL)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    discard_stdin();

    int cur_char;
    int num = 0;
    if ((cur_char = fgetc(in_file)) != EOF)
    {
        printf("1. ");
        fputc(cur_char, stdout);
        num = 1;

        while ((cur_char = fgetc(in_file)) != EOF)
        {
            fputc(cur_char, stdout);
            if (cur_char == '\n')
            {
                printf("%d. ", ++num);
            }
        }
    }
    printf("\n%d", num);
    _h_exit()
}
