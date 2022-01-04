#include <stdio.h>

#define R 0
#define I 1

int main()
{

    float real1, real2, imag1, imag2;

    printf("Input first numbers real part: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &real1);
    printf("Input first numbers imaginary part: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &imag1);
    printf("Input second numbers real part: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &real2);
    printf("Input first numbers imaginary part: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &imag2);

    float sum[] = { real1 + real2,
        imag1 + imag2 };
    float difference[] = { real1 - real2,
        imag1 - imag2 };
    float product[] = { real1 * real2 - imag1 * imag2,
        imag1 * real2 + imag2 * real1 };
    float denominator = real2 * real2 + imag2 * imag2;
    float quotient[] = { (real1 * real2 + imag1 * imag2) / denominator,
        (imag1 * real2 - imag2 * real1) / denominator };

    char i1_s[32], i2_s[32], s_s[32], d_s[32], p_s[32], q_s[32];
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(i1_s, "%+.3f", imag1);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(i2_s, "%+.3f", imag2);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(s_s, "%+.3f", sum[I]);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(d_s, "%+.3f", difference[I]);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(p_s, "%+.3f", product[I]);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    sprintf(q_s, "%+.3f", quotient[I]);

    printf("First number: %.3f%ci%s\n", real1, i1_s[0], i1_s + 1);
    printf("Second number: %.3f%ci%s\n", real2, i2_s[0], i2_s + 1);
    printf("Sum: %.3f%ci%s\n", sum[R], s_s[0], s_s + 1);
    printf("Difference: %.3f%ci%s\n", difference[R], d_s[0], d_s + 1);
    printf("Product: %.3f%ci%s\n", product[R], p_s[0], p_s + 1);
    printf("Quotient: %.3f%ci%s\n", quotient[R], q_s[0], q_s + 1);

    return 0;
}
