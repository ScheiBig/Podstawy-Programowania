#include <stdio.h>
#include <string.h>

#define IS_LETTER(A) ('a' <= A && A <= 'z' || 'A' <= A && A <= 'Z')

#define BUF_LEN 100
#define OUT_LEN 200

int main()
{

    char buffer[BUF_LEN + 2] = { (char)0 }, output[OUT_LEN + 1] = { (char)0 };
    size_t out_len = 0;
    printf("Enter your string: ");
    fgets(buffer, BUF_LEN + 2, stdin);
    if (buffer[strlen(buffer) - 1] <= ' ')
    {
        buffer[strlen(buffer) - 1] = (char)0;
    }
    size_t str_len = strlen(buffer);
    if (str_len > BUF_LEN)
    {
        fprintf(stderr, "Input is too long\n");
        return 2;
    }

    for (size_t i = 0; i < str_len; ++i)
    {
        if ('1' <= buffer[i] && buffer[i] <= '9')
        {
            if (!IS_LETTER(buffer[i + 1]))
            {
                fprintf(stderr, "Incorrect input\n");
                return 1;
            }
            for (size_t j = 0; j < (size_t)buffer[i] - '0'; ++j)
            {
                output[out_len] = buffer[i + 1];
                if (++out_len > OUT_LEN)
                {
                    fprintf(stderr, "Output is too long\n");
                    return 3;
                }
            }
            ++i;
        }
        else if (IS_LETTER(buffer[i]))
        {
            output[out_len] = buffer[i];
            if (++out_len > OUT_LEN)
            {
                fprintf(stderr, "Output is too long\n");
                return 3;
            }
        }
        else
        {
            fprintf(stderr, "Incorrect input\n");
            return 1;
        }
    }

    for (size_t i = strlen(output); i > 0; --i)
    {
        printf("%c", output[i - 1]);
    }
    printf("\n");

    return 0;
}
