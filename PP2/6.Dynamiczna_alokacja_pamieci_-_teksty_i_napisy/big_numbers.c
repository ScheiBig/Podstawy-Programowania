#include "big_numbers.h"

#include <stdlib.h>
#include <string.h>

int create(big_numbers_ps bn, int capacity)
{
    if (bn == null || capacity <= 0) { return 1; }
    bn->big_number = (cstring*)calloc((unsigned)capacity, sizeof(cstring));
    if (bn->big_number == null) { return 2; }
    bn->capacity = capacity;
    bn->size = 0;
    return 0;
}

int create_big_numbers(big_numbers_ps* bn, int capacity)
{
    if (bn == null || capacity <= 0) { return 1; }
    *bn = (big_numbers_ps)calloc(1u, sizeof(big_numbers_s));
    if (*bn == null) { return 2; }
    switch (create(*bn, capacity))
    {
    case 1:
        free(*bn);
        *bn = null;
        return 1;
    case 2:
        free(*bn);
        *bn = null;
        return 2;
    default:
        return 0;
    }

}

int _destroy_check(big_numbers_ps bn)
{
    if (bn == null || bn->big_number == null || bn->size < 0 || bn->capacity <= 0 || bn->size > bn->capacity) { return 1; }
    return 0;
}

void destroy(big_numbers_ps bn)
{
    if (_destroy_check(bn)) { return; }
    for (cstring* n = bn->big_number; n < bn->big_number + bn->size; ++n)
    {
        if (*n != null) { free(*n); }
        else { break; }
    }
    free(bn->big_number);
}

void destroy_big_numbers(big_numbers_ps* bn)
{
    if (bn == null || *bn == null) { return; }
    if (_destroy_check(*bn)) { return; }
    destroy(*bn);
    free(*bn);
    *bn = null;
}

int validate(c_cstring number)
{
    if (number == null) { return -1; }
    if (strlen(number) == 0) { return 2; }
    
    c_cstring temp = number;
    if (*number == '0' && strlen(number) != 1) { return 2; }
    if (*number == '-' && *(number + 1) == '0' && strlen(number) != 2) { return 2; }
    if (*temp == '-') { ++temp; }
    
    do
    {
        if (!is_digit(*temp)) { return 2; }
    } while (*(++temp) != str_term);
    return 0;
}

int add_big_number(big_numbers_ps bn, const char* big_number)
{
    if (_destroy_check(bn) || big_number == null || strlen(big_number) == 0 || validate(big_number)) { return 1; }
    if (bn->size == bn->capacity) { return 3; }
    cstring* next_num = bn->big_number + bn->size;
    *next_num = (cstring)calloc(strlen(big_number) + 1, sizeof(char));
    if (*next_num == null) { return 2; }
    //NOLINTNEXTLINE(clang-tidy(clang-analyzer-security.insecureAPI.strcpy -> Dante doesn't provide *_s
    strcpy(*next_num, big_number);
    bn->size++;
    return 0;
}

void display(c_big_numbers_ps bn)
{
    if (_destroy_check((big_numbers_ps)bn)) { return; }
    for (cstring* n = bn->big_number; n < bn->big_number + bn->size; ++n)
    {
        printf_ln("%s", *n);
    }
}
