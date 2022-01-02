#include <stdio.h>
#include <math.h>

#define MAT_ROW 11
#define MAT_COL 11

int main()
{
    int mul_table[MAT_ROW][MAT_COL] = { 0 };

    for (size_t r = 0; r < MAT_ROW; ++r)
    {
        for (size_t c = 0; c < MAT_COL; ++c)
        {
            mul_table[r][c] = r * c;
        }
    }

    for (size_t r = 0; r < MAT_ROW; ++r)
    {
        for (size_t c = 0; c < MAT_COL; ++c)
        {
            printf("%3d ", mul_table[r][c]);
        }
        printf("\n");
    }

    return 0;
}
