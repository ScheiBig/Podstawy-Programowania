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
    srand(time(NULL));
    char buffer[31];

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }
    FILE* out_file = register_file_pointer(fopen(buffer, "wb"));
    if (out_file == NULL)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }
    discard_stdin();

    float nums[100];
    for (float* s = nums; s < nums + 100; ++s)
    {
        *s = clip_range(rand(), -10000, 10000) / 100.0f;
    }
    fwrite(nums, sizeof(*nums), 100, out_file);
    
    print_ln("File saved");
    _h_exit()
}
