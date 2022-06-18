#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>

#define null NULL
#define str_term (char)0
typedef const char* c_cstring;
typedef char* cstring;

typedef struct point_t
{
    int x;
    int y;
} point_s;

int my_printf(cstring format, ...);
int my_scanf(cstring format, ...);

int pr_string(cstring s);
int pr_int(long i);
int pr_float(double f);
int pr_frac(double f, size_t positions);
int pr_point(point_s p);

int sc_int(int* i, long* l);
int sc_float(double* f);
int sc_point(point_s* p);
void sc_whitespaces();

long int_rev(int val);
size_t int_len(long long val);
int peekc(FILE* stream);


enum type
{
    _STRING = 's', _INT = 'd', _FLOAT = 'f', _POINT = 'p'
};

int main(int argc, char** argv) { return 0; }

int my_printf(cstring format, ...)
{
    if (format == null || strlen(format) == 0) { return 0; }
    va_list args;
    va_start(args, format);
    c_cstring f = (c_cstring)format;
    size_t pc = 0;

    while (*f != str_term)
    {
        if (*f == '%')
        {
            switch (*(++f))
            {
            case _STRING:
                pc += pr_string(va_arg(args, cstring));
                break;
            case _INT: {
                pc += pr_int(va_arg(args, int));
                break;
            }
            case _FLOAT:
                pc += pr_float(va_arg(args, double));
                break;
            case _POINT:
                pc += pr_point(va_arg(args, point_s));
                break;
            default:
                va_end(args);
                return EOF;
            }
        }
        else
        {
            putc(*f, stdout);
            ++pc;
        }
        ++f;
    }

    va_end(args);
    return pc;
}

int my_scanf(cstring format, ...)
{
    if (format == null || strlen(format) == 0) { return 0; }
    va_list args;
    va_start(args, format);
    c_cstring f = (c_cstring)format;
    size_t vc = 0;

    sc_whitespaces();
    while (*f != str_term)
    {
        if (*f == '%')
        {
            switch (*(++f))
            {
            case _INT: {
                vc += sc_int(va_arg(args, int*), null);
                break;
            }
            case _FLOAT:
                vc += sc_float(va_arg(args, double*));
                break;
            case _POINT:
                vc += sc_point(va_arg(args, point_s*));
                break;
            default:
                va_end(args);
                return EOF;
            }
        }
        else if (*f == ' ') { sc_whitespaces(); }
        else
        {
            va_end(args);
            return EOF;
        }
        ++f;
    }

    va_end(args);
    return vc;
}


int pr_string(cstring s)
{
    for (cstring c = s; *c != str_term;
        putc(*c, stdout),
        ++c);

    return strlen(s);
}

int pr_int(long i)
{
    size_t pc = 0;
    if (i < 0)
    {
        putc('-', stdout);
        ++pc;
    }
    else if (i == 0)
    {
        putc('0', stdout);
        return 1;
    }

    for (long rev = int_rev(i); rev != 0;
        putchar('0' + rev % 10),
        rev /= 10,
        ++pc);

    if (pc < int_len(i))
    {
        for (int j = int_len(i) - pc; j > 0;
            --j,
            ++pc,
            putc('0', stdout));
    }

    return pc;
}

int pr_float(double f)
{
    size_t pc = 1;
    pc += pr_int(f);
    putc('.', stdout);

    double frac = (f - (int)f);
    pc += pr_frac(frac, 5);

    return pc;
}

int pr_frac(double f, size_t positions)
{
    for (size_t i = 0; i < positions;
        ++i,
        f *= 10,
        putc('0' + abs((int)f % 10), stdout));
    return positions;
}

int pr_point(point_s p)
{
    size_t pc = 3;
    putc('(', stdout);
    pc += pr_int(p.x);
    putc(' ', stdout);
    pc += pr_int(p.y);
    putc(')', stdout);

    return pc;
}


int sc_int(int* i, long* l)
{
    int sign = 1;
    long result = 0;
    long long Result = 0;
    int c;
    if ((c = getc(stdin)) == '-') { sign *= -1; }
    else { ungetc(c, stdin); }

    int cnt = 0;
    
    while (isdigit(c = getc(stdin)) && !isspace(c))
    {
        if (result * 10 < INT_MAX)
        {
            result *= 10;
            result += c - '0';
        }
        if (Result * 10 < LONG_MAX)
        {
            Result *= 10;
            Result += c - '0';
        }
        ++cnt;
    }
    ungetc(c, stdin);
    if (cnt == 0) { return 0; }
    if (i != null) { *i = (int)result * sign; }
    if (l != null) { *l = (long)Result * sign; }
    return 1;
}

int sc_float(double* f)
{
    int is;
    long int_result;
    is = sc_int(null, &int_result);
    if (!is) { return 0; }
    int c = getc(stdin);
    if ((!isdigit(c) && c != '.' )||
        isspace(peekc(stdin)) || peekc(stdin) == str_term)
    {
        double result = (double)int_result;
        *f = result;
        return 1;
    }
    else if (isdigit(peekc(stdin)) && c == '.');
    else { return 0; }

    double result = 0;
    int cnt = 0;

    while (isdigit(c = getc(stdin)) && !isspace(c))
    {
        result *= 10;
        result += c - '0';
        ++cnt;
    }
    ungetc(c, stdin);
    for (int i = 0; i < cnt; ++i, result /= 10);

    result += labs(int_result);
    if (int_result < 0) { result *= -1; }
    
    *f = result;

    return 1;
}

int sc_point(point_s* p)
{
    int is;
    point_s result;
    if (peekc(stdin) == '(') { getc(stdin); }
    else { return 0; }
    is = sc_int(&result.x, null);
    if (!is) { return 0; }
    if (getc(stdin) != ' ') { return 0; }
    if (!isdigit(peekc(stdin)) && peekc(stdin) != '-') { return 0; }
    is *= sc_int(&result.y, null);
    if (!is || getc(stdin) != ')') { return 0; }
    getc(stdin);

    *p = result;

    return 2;
}

void sc_whitespaces()
{
    int c;
    while (isspace(c = getc(stdin)));
    ungetc(c, stdin);
}


long int_rev(int val)
{
    long rev = 0;
    val = abs(val);
    for (val = abs(val); val != 0;
        rev *= 10,
        rev += val % 10,
        val /= 10);
    return rev;
}

size_t int_len(long long val)
{
    size_t len = 0;
    if (val < 0) { ++len; }
    else if (val == 0) { return 1; }

    for (val = llabs(val); val != 0;
        ++len,
        val /= 10);
    return len;
}

int peekc(FILE* stream)
{
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}
