#pragma once
#include <stdio.h>

#define SQR(a) ((a) * (a))
#define MIN(a, b) ((a) < (b) ? (a) :(b))
#define MAX(a, b) ((a) > (b) ? (a) :(b))

// Obliczania liczby ustawionych i wyzerowanych bitów w liczbie przekazanej do makra.Makro powinno przyjąć liczbę całkowitą, dla której ma zostać wyznaczona statystyka i dwa wskaźniki na liczby całkowite, do której ma zostać zapisany wynik.
// Przykład wywołania :
#define COUNT_BITS(v, p_s, p_c) do \
{\
    if (p_s == NULL || p_c == NULL) { break; } \
    *(p_s) = 0; \
    *(p_c) = 0; \
    for (size_t i = 0; i < sizeof(v); ++i) \
    { \
        for (size_t j = 0; j < 8; ++j) \
        { \
            (((v) >> (i * 8 + j)) & 0x1) ? ++(*(p_s)) : ++(*(p_c)); \
        }\
    }\
} while (0)

// Wyświetlania reprezentacji binarnej liczby przekazanej do makra.Przykład wywołania :
#define DISPLAY_BITS(v) do \
{ \
    const char* f = NULL; \
    switch(sizeof(v)) \
    { \
    case 1: f = "%hhu"; break; \
    case 2: f = "%hu"; break; \
    case 4: f = "%u"; break; \
    case 8: f = "%lu"; break; \
    } \
    if (f == NULL) { break; } \
    for (long i = (signed)sizeof(v) - 1; i >= 0; --i) \
    { \
        for (int j = 7; j >= 0; --j) \
        { \
            printf(f, ((v) >> ((unsigned)i * 8 + (unsigned)j)) & 0x1); \
        } \
    } \
} while (0)

// Odwracania kolejności bitów w liczbie.Przykład wywołania :
#define REVERSE_BITS(p) \
do \
{ \
    if ((p) == NULL) { break; } \
    switch (sizeof(*(p))) \
    { \
    case 1: { \
        unsigned char rv = 0; \
        unsigned char t = *(p); \
        for (size_t i = 0; i < (sizeof(*(p)) * 8); ++i, t >>= 0x1) \
        { \
            rv = (rv << 0x1) | (t & 0x1); \
        } \
        *(p) = rv; \
        break; \
    } \
    case 2: { \
        unsigned short rv = 0; \
        unsigned short t = *(p); \
        for (size_t i = 0; i < (sizeof(*(p)) * 8); ++i, t >>= 0x1) \
        { \
            rv = (rv << 0x1) | (t & 0x1); \
        } \
        *(p) = rv; \
        break; \
    } \
    case 4: { \
        unsigned int rv = 0; \
        unsigned int t = *(p); \
        for (size_t i = 0; i < (sizeof(*(p)) * 8); ++i, t >>= 0x1) \
        { \
            rv = (rv << 0x1) | (t & 0x1); \
        } \
        *(p) = rv; \
        break; \
    } \
    case 8: { \
        unsigned long rv = 0; \
        unsigned long t = *(p); \
        for (size_t i = 0; i < (sizeof(*(p)) * 8); ++i, t >>= 0x1) \
        { \
            rv = (rv << 0x1) | (t & 0x1); \
        } \
        *(p) = rv; \
        break; \
    } \
    } \
 \
} while (0)