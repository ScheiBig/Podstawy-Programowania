#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

#include "my_utils_v3.h"

void show(const void* ptr, size_t count);
void inverse_bits(void* ptr, size_t offset, size_t count);

int main()
{
    char text[101];
    print_ln("Enter a string:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%100[^\n]s", text);
    size_t len = strlen(text) + 1;
    show(text, len);
    print_n();
    inverse_bits(text, 0, len);
    show(text, len);
    print_n();

    return 0;
}


void show(const void* ptr, size_t count)
{
    if (ptr == null || count == 0) return;
    const byte* p = (const byte*)ptr;
    for (; p < (const byte*)ptr + count - 1; ++p) { printf("%02x ", *p); }
    printf("%02x", *p);
}

void inverse_bits(void* ptr, size_t offset, size_t count)
{
    if (ptr == null || count == 0) return;
    for (byte* p = (byte*)ptr + offset; p < (byte*)ptr + offset + count; ++p) { *p = ~*p; }
}
