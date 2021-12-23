#define SIGN(A) ((A >> sizeof(A) * 8-1) & 0x1)

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

#define IS_LETTER(A) ('a' <= A && A <= 'z' || 'A' <= A && A <= 'Z')
#define IS_UPPERCASE(A) ('A' <= A && A <= 'Z')
#define IS_LOWERCASE(A) ('a' <= A && A <= 'z')

#define COND_ASSIGN_L(A, B) (A = A < B ? B : A)
#define COND_ASSIGN_LE(A, B) (A = A <= B ? B : A)
#define COND_ASSIGN_G(A, B) (A = A > B ? B : A)
#define COND_ASSIGN_GE(A, B) (A = A >= B ? B : A)

// needs <math.h>
#define cbrt(x) _Generic((x), \
    long double: cbrtl, \
    default: cbrt, \
    float: cbrtf \
)(x)