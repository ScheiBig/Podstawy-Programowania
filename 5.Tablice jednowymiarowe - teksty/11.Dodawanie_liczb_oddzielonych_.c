#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>

#define IS_NUMBER(chr) ('0' <= chr && chr <= '9')
#define eprintf(msg) fprintf(stderr, msg)
#define _e_exit(eno, msg) { eprintf(msg); return eno; }

#define BUF_LEN 1000
#define ARR_LEN 500

long array[ARR_LEN] = { 0 };

int main()
{
    char in_buffer[BUF_LEN + 1] = { (char)0 };
    printf("Enter your string: ");
    fgets(in_buffer, BUF_LEN + 1, stdin);
    if (in_buffer[strlen(in_buffer) - 1] <= ' ')
    {
        in_buffer[strlen(in_buffer) - 1] = (char)0;
    }

    size_t str_len = strlen(in_buffer);
    int num_buffer[ARR_LEN], offset;
    size_t num_len = 0, arr_len = 0;
    for (size_t i = 0; i < str_len + 1;)
    {
        if (IS_NUMBER(in_buffer[i]))
        {
            if (sscanf(in_buffer + i, "%d%n", num_buffer + (num_len++), &offset) != 1)
            {
                _e_exit(1, "Incorrect input\n");
            }
            i += offset;
            if (in_buffer[i] == '-') ++i;
            else if (in_buffer[i] == '|' || in_buffer[i] == (char)0)
            {
                for (size_t j = 0; j < num_len; ++j) array[arr_len] += num_buffer[j];
                ++arr_len;
                num_len = 0;
                num_buffer[0] = 0;
                ++i;
            }
            else
            {
                _e_exit(1, "Incorrect input\n");
            }
        }
        else if (in_buffer[i] == '|')
        {
            array[arr_len++] = 0;
            ++i;
        }
        else
        {
            _e_exit(1, "Incorrect input\n");
        }
    }

    for (size_t i = 0; i < arr_len; ++i)
    {
        printf("%ld ", array[i]);
    }
    printf("\n");
    return 0;
}
