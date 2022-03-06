#include "vector_utils.h"

#include <stdio.h>

int read_vector(int vec[], int size, int stop_value)
{
    if (size <= 0) return vuVEC_invalid;
    int i;
    int temp;
    for (i = 0; i < size; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %d", &temp) != 1)
        {
            return vuDATA_invalid;
        }
        else if (temp == stop_value)
        {
            return i;
        }
        else
        {
            vec[i] = temp;
        }
    }
    char trash;
    do
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%c", &trash);
    } while (trash != '\n');

    return i;
}

void display_vector(const int vec[], int size)
{
    if (size <= 0) return;
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", vec[i]);
    }

    printf("\n");
}
