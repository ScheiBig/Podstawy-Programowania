#define SIGN(A) ((A >> sizeof(A) * 8-1) & 0x1)

#define A_SIZE(A) (sizeof(A) / sizeof(A[0]))

#define IS_LETTER(A) ('a' <= A && A <= 'z' || 'A' <= A && A <= 'Z')