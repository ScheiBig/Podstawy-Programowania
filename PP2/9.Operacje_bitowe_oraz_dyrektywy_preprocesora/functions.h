#pragma once
#include <stdio.h>

#define SQR(a) ((a) * (a))
#define MIN(a, b) ((a) < (b) ? (a) :(b))
#define MAX(a, b) ((a) > (b) ? (a) :(b))



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



#define CREATE_READ_FUNCTIONS(TYPE, FORMAT) \
    int read_ ## TYPE(TYPE* data, int size) \
    { \
        if (size <= 0 || data == NULL) { return 1; } \
        for (int i = 0; i < size; ++i) \
        { \
            if (scanf(FORMAT, data + i) != 1) { return 2; } \
        } \
        while (getc(stdin) != '\n'); \
        return 0; \
    }

#include <stdlib.h>
#define CREATE_SORT_FUNCTIONS(TYPE) \
    int comp_ ## TYPE(const void* a, const void* b) { return (*(TYPE*)a > *(TYPE*)b) ? 1 : (*(TYPE*)a < *(TYPE*)b) ? -1 : 0; } \
    int sort_ ## TYPE(TYPE* data, int size) \
    { \
        if (size <= 0 || data == NULL) return 1; \
        qsort(data, (unsigned)size, sizeof(TYPE), comp_ ## TYPE); \
        return 0; \
    }


#define CREATE_DISPLAY_FUNCTIONS(TYPE, FORMAT) \
    void display_ ## TYPE(const TYPE* data, int size) \
    { \
        if (size <= 0 || data == NULL) return; \
        for (int i = 0; i < size; ++i) { printf(FORMAT " ", *(data + i)); } \
        printf("\n"); \
    }



#define DEFINE_ARRAY(TYPE) \
    typedef struct array_ ## TYPE ## _t \
    { \
        int size; \
        int capacity; \
        TYPE* data; \
    } array_ ## TYPE ## _s;

#define CREATE_ARRAY(TYPE) \
    array_ ## TYPE ## _s* create_array_ ## TYPE(int size) \
    { \
        if (size <= 0) { return NULL; } \
        array_ ## TYPE ## _s* array = (array_ ## TYPE ## _s*)calloc(1, sizeof(array_ ## TYPE ## _s)); \
        if (array == NULL) { return NULL; } \
        if ((array->data = (TYPE*)calloc((unsigned)size, sizeof(TYPE))) == NULL) \
        { \
            free(array); \
            return NULL; \
        } \
        array->size = 0; \
        array->capacity = size; \
        return array; \
    }

#define FREE_ARRAY(TYPE) \
    void free_array_ ## TYPE(array_ ## TYPE ## _s* array) \
    { \
        if (array == NULL) { return; } \
        if (array->capacity <= 0) { return; } \
        if (array->size < 0) { return; } \
        if (array->size > array->capacity) { return; } \
        if (array->data != NULL) { free(array->data); } \
        free(array); \
    }

#include <string.h>
#define SAVE_ARRAY(TYPE) \
    int save_array_ ## TYPE(const array_ ## TYPE ## _s* array, const char* filename) \
    { \
        if (array == NULL || array->data == NULL || array->capacity <= 0 || array->size <= 0 || \
             array->size > array->capacity || filename == NULL || strlen(filename) == 0) { return 1; } \
        FILE* f = fopen(filename, "wb"); \
        if (f == NULL) { return 2; } \
        fwrite(&array->size, sizeof(int), 1u, f); \
        fwrite(array->data, sizeof(TYPE), (unsigned)array->size, f); \
        fclose(f); \
        return 0; \
    }

#define LOAD_ARRAY(TYPE) \
    int load_array_ ## TYPE(array_ ## TYPE ## _s** array, const char* filename) \
    { \
        if (array == NULL || filename == NULL || strlen(filename) == 0) { return 1; } \
        FILE* f = fopen(filename, "rb"); \
        if (f == NULL) { return 2; } \
        int size; \
        if (fread(&size, sizeof(int), 1u, f) != 1u || size <= 0) \
        { \
            fclose(f); \
            return 3; \
        } \
        if ((*array = create_array_ ## TYPE(size)) == NULL) \
        { \
            fclose(f); \
            return 4; \
        } \
        if (fread((*array)->data, sizeof(TYPE), (unsigned)size, f) != (unsigned)size) \
        { \
            free_array_ ## TYPE(*array); \
            fclose(f); \
            return 3; \
        } \
        (*array)->size = (unsigned)size; \
        fclose(f); \
        return 0; \
    }

#define SORT_ARRAY(TYPE) \
    CREATE_SORT_FUNCTIONS(TYPE) \
    int sort_array_ ## TYPE(struct array_ ## TYPE ## _t* array) \
    { \
        if (array == NULL || array->data == NULL || array->capacity <= 0 || array->size <= 0 || \
            array->size > array->capacity) { return 1; } \
        sort_ ## TYPE(array->data, array->size); \
        return 0; \
    }
