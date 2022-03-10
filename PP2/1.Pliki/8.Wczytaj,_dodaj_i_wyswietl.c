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


    FILE* file = register_file_pointer(fopen(buffer, "r"));
    if (file == NULL)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg);
    }

    long sum = 0;
    long num;
    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        switch (fscanf(file, "%ld", &num))
        {
        case EOF:
            goto break_while;
        case 1: {
            sum += num;
            break;
        }
        default:
            _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
        }
    }
break_while: {}
    
    printf_ln("%ld", sum);
    _h_exit()
}
