#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()
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
        _mh_exit(eFILE_noaccess_eno, eFILE_noaccess)
    }

    FILE* in_file = register_file_pointer(fopen(buffer, "r"));
    if (in_file == NULL)
    {
        _mh_exit(eFILE_noaccess_eno, eFILE_noaccess)
    }
    discard_stdin();
    fseek(in_file, 0L, SEEK_END);
    
    int cur_char;
    int num = 0;
    long cur_pos = ftell(in_file);
    if (cur_pos == 0)
    {
        print_ln("Nothing to show");
        _h_exit()
    }
    bool is_finished = (cur_pos == 0);
    while (!is_finished)
    {
        while (true)
        {
            --cur_pos;
            if (cur_pos < 0L)
            {
                is_finished = true;
                break;
            }
            fseek(in_file, cur_pos, SEEK_SET);
            if (fgetc(in_file) == '\n')
            {
                break;
            };
            fseek(in_file, cur_pos, SEEK_SET);
        }
        printf("%d. ", ++num);
        while (true)
        {
            cur_char = fgetc(in_file);
            if (cur_char == EOF || cur_char == '\n')
            {
                fputc('\n', stdout);
                break;
            }
            fputc(cur_char, stdout);
        }
    }
    _h_exit()
}

