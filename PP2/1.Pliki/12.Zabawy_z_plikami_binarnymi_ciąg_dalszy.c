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

    float nums[100] = { 0.0 };
    if (fread(nums, sizeof(*nums), 100, in_file) != 100)
    {
        _mh_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    print_ln("Enter output file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    FILE* out_file = register_file_pointer(fopen(buffer, "wb"));
    if (out_file == NULL)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }
    discard_stdin();

    long double t_sum = 0;
    for (float* s = nums; s < nums + 100; ++s)
    {
        t_sum += *s;
    }
    float avg = (float)t_sum / 100;
    float sum = (float)t_sum;
    fwrite(&sum, sizeof(sum), 1, out_file);
    fwrite(&avg, sizeof(avg), 1, out_file);

    print_ln("File saved");
    _h_exit()
}
