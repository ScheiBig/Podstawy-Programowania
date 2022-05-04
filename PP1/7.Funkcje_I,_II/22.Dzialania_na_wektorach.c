#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_utils.h"

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3);

int read_vector(int vec[], int size, int stop_value);
void display_vector(const int vec[], int size);

#define VEC_overflow -2
#define DATA_invalid -2
#define VEC_invalid -1

#define DATA_none 2
#define INPUT_invalid 1

#define MAX_LEN 50
#define EOV 0

int main()
{
    int vec1[MAX_LEN], vec2[MAX_LEN];
    int v1_len, v2_len;
    int temp;
    print_ln("Enter a first vector");
    switch (temp = read_vector(vec1, MAX_LEN, EOV))
    {
    case DATA_invalid: { _e_exit(INPUT_invalid, "Incorrect input") }
    case 0: { _e_exit(DATA_none, "Not enough data available") }
    default: v1_len = temp;
    }
    print_ln("Enter a second vector");
    switch (temp = read_vector(vec2, MAX_LEN, EOV))
    {
    case DATA_invalid: { _e_exit(INPUT_invalid, "Incorrect input") }
    case 0: { _e_exit(DATA_none, "Not enough data available") }
    default: v2_len = temp;
    }

    display_vector(vec1, v1_len);
    display_vector(vec2, v2_len);
    int vec_out[MAX_LEN];
    switch (temp = concat_begin(vec1, v1_len, vec2, v2_len, vec_out, MAX_LEN))
    {
    case VEC_overflow: {
        eprint_ln("Output buffer is too small");
        return 0;
    }
    default: display_vector(vec_out, temp);
    }
    switch (temp = concat_end(vec1, v1_len, vec2, v2_len, vec_out, MAX_LEN))
    {
    case VEC_overflow: {
        eprint_ln("Output buffer is too small");
        return 0;
    }
    default: display_vector(vec_out, temp);
    }
    switch (temp = concat_zip(vec1, v1_len, vec2, v2_len, vec_out, MAX_LEN))
    {
    case VEC_overflow: {
        eprint_ln("Output buffer is too small");
        return 0;
    }
    default: display_vector(vec_out, temp);
    }

    return 0;
}

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (size <= 0 || size2 <= 0 || size3 <= 0) return VEC_invalid;
    if ((size + size2) > size3) return VEC_overflow;
    int j = 0;
    for (int i = 0; i < size; ++i, ++j)
    {
        dest[j] = first[i];
    }
    for (int i = 0; i < size2; ++i, ++j)
    {
        dest[j] = second[i];
    }
    return j;
}

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (size <= 0 || size2 <= 0 || size3 <= 0) return VEC_invalid;
    if ((size + size2) > size3) return VEC_overflow;
    int j = 0;
    for (int i = 0; i < size2; ++i, ++j)
    {
        dest[j] = second[i];
    }
    for (int i = 0; i < size; ++i, ++j)
    {
        dest[j] = first[i];
    }
    return j;
}
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (size <= 0 || size2 <= 0 || size3 <= 0) return VEC_invalid;
    if ((size + size2) > size3) return VEC_overflow;
    bool flip = true;
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < (size + size2); ++i)
    {
        if (flip)
        {
            if (j < size)
            {
                dest[i] = first[j++];
            }
            else
            {
                dest[i] = second[k++];
            }
            flip ^= true;
        }
        else
        {
            if (k < size2)
            {
                dest[i] = second[k++];
            }
            else
            {
                dest[i] = first[j++];
            }
            flip ^= true;
        }
    }
    return i;
}

int read_vector(int vec[], int size, int stop_value)
{
    if (size <= 0) return VEC_invalid;
    int i;
    int temp;
    for (i = 0; i < size; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf(" %d", &temp) != 1)
        {
            return DATA_invalid;
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
    
    print_ln("");
}
