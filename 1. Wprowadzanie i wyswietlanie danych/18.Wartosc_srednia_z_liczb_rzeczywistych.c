#include <stdio.h>

int main()
{
    float n0, n1, n2, n3, n4;
    printf("Input 5 numbers: \n");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f %f %f %f %f",
        &n0, &n1, &n2, &n3, &n4);
    printf("Yours numbers average: %.4f\n1 ",
        (n0 + n1 + n2 + n3 + n4)
        / 5);

    return 0;
}
