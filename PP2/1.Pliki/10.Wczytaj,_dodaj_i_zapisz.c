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

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }
    discard_stdin();
    FILE* in_file = register_file_pointer(fopen(buffer, "r"));
    if (in_file == NULL)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    fseek(in_file, 0L, SEEK_END);
    if (ftell(in_file) == 0)
    {
        _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    fseek(in_file, 0L, SEEK_SET);

    int any_num = 0;
    int c;
    while ((c = fgetc(in_file)) != EOF)
    {
        if (is_digit(c))
        {
            any_num = 1;
            break;
        }
    }
    if (!any_num)
    {
        _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    fseek(in_file, 0L, SEEK_SET);

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

    // FILE* tmp_file = register_file_pointer(tmpfile());
    FILE* tmp_file = register_file_pointer(fopen("temp", "w+"));

    int any_global = 0;
    int any = 0;
    int cur_num = 0;
    int cur_sum = 0;
    int cur_char;
    int prev_char = 0;
    char cur_ch;
    while (true)
    {
        switch (cur_char = fgetc(in_file))
        {
        case EOF:
            fputc(' ', tmp_file);
            fputc('0', tmp_file);
            fputc('\n', tmp_file);
            goto break_while;
        case '1':case '2':case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
            if (prev_char == '-')
            {
                fputc(prev_char, tmp_file);
            }
            fputc(cur_char, tmp_file);
            any = 1;
            any_global = 1;
            break;
        case '\n':
            fputc(' ', tmp_file);
            fputc('0', tmp_file);
            fputc('\n', tmp_file);
            any = 0;
            break;
        default:
            if (any == 1)
            {
                fputc(' ', tmp_file);
                fputc(' ', tmp_file);
                any = 0;
            }
            break;
        }
        prev_char = cur_char;
    }
break_while: {}
    fflush(tmp_file);
    fseek(tmp_file, 0L, SEEK_SET);
    if (!any_global)
    {
        _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    any = 0;
    while (true)
    {
        // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (fscanf(tmp_file, " %d%c", &cur_num, &cur_ch) == EOF)
        {
            break;
        }
        if (cur_ch == ' ')
        {
            cur_sum += cur_num;
            any = 1;
        }
        else
        {
            if (any == 1)
            {
                fprintf(out_file, "%d\n", cur_sum);
            }
            cur_sum = 0;
            any = 0;
        }
    }

    print_ln("File saved");
    _h_exit()
}
