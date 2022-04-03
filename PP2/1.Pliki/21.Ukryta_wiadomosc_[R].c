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

    char cur_char;
    while (true)
    {
        if ((cur_char = fgetc(in_file)) == '\n')
        {
            break;
        }
        else if (is_digit(cur_char) || cur_char == ' ')
        {
            continue;
        }
        else
        {
            _eh_exit(eFILE_corrupted_eno, eFILE_corrupted)
        }
    }
    fseek(in_file, 0L, SEEK_END);
    long max_pos = ftell(in_file);
    fseek(in_file, 0L, SEEK_SET);

    long next_pos;
    long cur_pos;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    while (fscanf(in_file, " %ld", &next_pos) == 1)
    {
        if (next_pos >= max_pos)
        {
            _eh_exit(eFILE_corrupted_eno, eFILE_corrupted)
        }
    }
    fseek(in_file, 0L, SEEK_SET);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    while (fscanf(in_file, " %ld", &next_pos) == 1)
    {
        cur_pos = ftell(in_file);
        fseek(in_file, next_pos, SEEK_SET);
        fputc(fgetc(in_file), stdout);
        fseek(in_file, cur_pos, SEEK_SET);
    }
    _h_exit()
}
