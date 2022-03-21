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
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }

    FILE* in_file;
    FILE* tmp_file;
    if ((tmp_file = register_file_pointer(fopen(buffer, "r"))))
    {
        release_file_pointer(tmp_file);
        in_file = register_file_pointer(fopen(buffer, "a+"));
    }
    else
    {
        in_file = register_file_pointer(fopen(buffer, "w+"));
    }

    
    if (in_file == NULL)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }
    discard_stdin();

    int cur_char = '\n';
    int prev_char = 0;

    // fseek(in_file, 0L, SEEK_END);

    print_ln("Enter input text: ");
    // cur_char = fgetc(stdin);
    while (true)
    {
        prev_char = cur_char;
        cur_char = fgetc(stdin);
        if (cur_char == '\n' && prev_char == '\n')
        {
            break;
        }
        fputc(cur_char, in_file);
    }

    print_ln("File saved");
    _h_exit()
}
