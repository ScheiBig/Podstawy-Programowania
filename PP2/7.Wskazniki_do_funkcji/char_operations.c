#include "char_operations.h"

#include <stdlib.h>
#include <string.h>

#include "my_utils_v3.h"

cstring letter_modifier(c_cstring input_text, char_op operation)
{
    if (input_text == null || strlen(input_text) == 0 || operation == null) { return null; }
    cstring result = (cstring)calloc(strlen(input_text) + 1, sizeof(char));
    if (result == null) { return null; }
    const char* c = input_text;
    char* r = result;
    for (; c < input_text + strlen(input_text); ++c, ++r)
    {
        *r = operation(*(char*)c);
    }
    return result;
}

char lower_to_upper(char c) { return to_uppercase(c); }

char upper_to_lower(char c) { return to_lowercase(c); }

char space_to_dash(char c) { return c == ' ' ? '_' : c; }

char reverse_letter(char c)
{
    if (is_uppercase(c)) { return 'Z' - c + 'A'; }
    else if (is_lowercase(c)) { return 'z' - c + 'a'; }
    else { return c; }
}
