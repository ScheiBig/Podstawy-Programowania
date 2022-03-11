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
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }

    long sum = 0;
    long count;
    long num;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    switch (fscanf(file, "%ld", &count))
    {
    case EOF: _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    case 1: break;
    default: _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    if (count <= 0)
    {
        _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    for (long i = 0; i < count; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        switch (fscanf(file, "%ld", &num))
        {
        case EOF: _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
        case 1: {
            sum += num;
            break;
        }
        default: _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
        }
    }
    double avg = sum / (double)count;

    printf_ln("%ld", sum);
    printf_ln("%lf", avg);
    _h_exit()
}
