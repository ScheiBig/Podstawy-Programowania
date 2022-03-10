#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils.h"

int main()
{
    int number;
    srand(time(NULL));

    char buffer[10];
    print_ln("Enter number of numbers");//NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" %d", &number) != 1)
    {
        _m_exit(eINPUT_invalid, eINPUT_invalid_msg)
    }
    else if (0 >= number || number > 1000)
    {
        _m_exit(eDATA_invalid, eDATA_invalid_msg)
    }
    FILE* cur_file;
    int i;
    int j;
    for (i = 0; i < number / 10; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        sprintf(buffer, "%d.txt", i);
        cur_file = fopen(buffer, "w");
        if (cur_file == NULL)
        {
            _m_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
        }
        printf("%s\n", buffer);
        for (j = 0; j < 10; ++j)
        {
            fprintf(cur_file, "%d\n", clip_range(rand(), 0, 1001));
        }
        fclose(cur_file);
    }
    if (number % 10 > 0)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        sprintf(buffer, "%d.txt", i);
        cur_file = fopen(buffer, "w");
        if (cur_file == NULL)
        {
            _m_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
        }
        printf("%s\n", buffer);
        for (j = 0; j < number % 10; ++j)
        {
            fprintf(cur_file, "%d\n", clip_range(rand(), 0, 1001));
        }
        fclose(cur_file);
    }

    return 0;
}
