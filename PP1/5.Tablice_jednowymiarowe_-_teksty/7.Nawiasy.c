#include <stdio.h>
#include <string.h>

#define BUF_LEN 52

int main()
{
    size_t  max_nesting_length = 0, nesting_indices[BUF_LEN / 2] = { 0 }, nesting_indices_size = 0, opened_braces = 0;
    char buffer[BUF_LEN] = { (char)0 };

    printf("Enter your expression: ");
    fgets(buffer, BUF_LEN, stdin);
    if (buffer[BUF_LEN - 2] >= ' ')
    {
        fprintf(stderr, "Input is too long\n");
        return 1;
    }

    for (size_t i = 0; i < strlen(buffer); ++i)
    {
        if (buffer[i] == '(')
        {
            ++opened_braces;
        }
        else
        {
            if (max_nesting_length <= opened_braces)
            {
                if (max_nesting_length != opened_braces)
                {
                    max_nesting_length = opened_braces;
                    nesting_indices_size = 0;
                }
                nesting_indices[nesting_indices_size++] = i - 1;
            }
            --opened_braces;
        }
    }

    printf("%zu", max_nesting_length);
    for (size_t i = 0; i < nesting_indices_size; ++i)
    {
        printf(" %zu", nesting_indices[i]);
    }
    printf("\n");

    return 0;
}
