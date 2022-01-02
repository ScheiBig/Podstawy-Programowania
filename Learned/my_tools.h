#define eprintf(msg) fprintf(stderr, msg)
#define _e_exit(eno, msg) { eprintf(msg); return eno; }

#define SIGN(num) ((num >> sizeof(num) * 8 - 1) & 0x1)

#define A_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define IS_LETTER(chr) ('a' <= chr && chr <= 'z' || 'A' <= chr && chr <= 'Z')
#define IS_UPPERCASE(chr) ('A' <= chr && chr <= 'Z')
#define IS_LOWERCASE(chr) ('a' <= chr && chr <= 'z')
#define IS_NUMBER(chr) ('0' <= chr && chr <= '9')

#define COND_ASSIGN_L(to, arg) (to = to < arg ? arg : to)
#define COND_ASSIGN_LE(to, arg) (to = to <= arg ? arg : to)
#define COND_ASSIGN_G(to, arg) (to = to > arg ? arg : to)
#define COND_ASSIGN_GE(to, arg) (to = to >= arg ? arg : to)

// needs <math.h>, here only for now
#define cbrt(x) _Generic((x), \
    long double: cbrtl, \
    default: cbrt, \
    float: cbrtf \
)(x)

// needs <stddef.h>, useful via <stdio.h>
#define _REGISTER_ARRAY(type) \
    typedef struct \
    { \
        type* pointer;\
        size_t size; \
    } array__##type##_; \
    \
    array__##type##_ wrap_array__##type##_(type* pointer, size_t size) \
    { \
        array__##type##_ ret; \
        ret.pointer = pointer; \
        ret.size = size; \
        return ret;\
    }