#include <stdio.h>

int main()
{
    int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
    printf("Input 10 numbers: \n");
    scanf("%d %d %d %d %d %d %d %d %d %d",
        &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);
    printf("Yours numbers average: %.4f\n1 ",
        (n0 + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9)
        / 10.0);

    return 0;
}
