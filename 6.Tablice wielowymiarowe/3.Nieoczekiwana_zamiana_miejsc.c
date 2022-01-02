#include <stdio.h>
#include <math.h>

#define eprintf(msg) fprintf(stderr, msg)
#define _e_exit(eno, msg) { eprintf(msg); return eno; }

#define MAT_SIZ 5

void swap(int* a1, int* a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

int main()
{
    int mul_table[MAT_SIZ][MAT_SIZ] = { 0 };

    int a = 5, b = 9;

    swap(&a, &b);

    printf("Enter a 5x5 matrix:\n");

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            if (scanf("%d", *(mul_table + r) + c) != 1) _e_exit(1, "Incorrect input\n");
        }
    }

    for (size_t i = 0; i < MAT_SIZ; ++i)
    {
        swap(*(mul_table + i) + i, *(mul_table + i) + (MAT_SIZ - i - 1));
    }


    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            printf("%d ", mul_table[r][c]);
        }
        printf("\n");
    }

    return 0;
}
