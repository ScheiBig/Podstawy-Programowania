#include <stdio.h>

int main()
{
    int col, row_num, success;
    char row;

    printf("Input chessboard field: ");
    success = scanf("%c%1d", &row, &col);

    if ((success - 2) ||
        col < 1 || col > 8 ||
        row < 'a' || row > 'h')
    {
        printf("Incorrect input\n");
        return 1;
    }

    row_num = (int)(row - 'a') + 1;
    if ((col + row_num) % 2)
    {
        printf("white\n");
    }
    else
    {
        printf("black\n");
    }

    return 0;
}
