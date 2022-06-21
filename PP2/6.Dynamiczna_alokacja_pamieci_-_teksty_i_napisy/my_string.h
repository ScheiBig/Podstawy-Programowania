#pragma once

#include "my_utils_v3.h"
#include <string.h>
#include <stdlib.h>

int discard_stdin();
int discard_stream(p_file);

cstring string_prepend_c(cstring, char);
cstring string_prepend(cstring, cstring);
cstring string_append_c(cstring, char);
cstring string_append(cstring, cstring suffix);

int string_endswith(c_cstring, c_cstring);

cstring strncpy_term(cstring, c_cstring, size_t);

void string_reverse(cstring);
void string_reverse_lim(cstring, size_t);
void string_flip_case(cstring);

cstring alloc_string_append(cstring, cstring, size_t);
cstring alloc_string_prepend(cstring, cstring, size_t);

size_t pagelen(cstring*);
cstring* alloc_string_page_append(cstring*, size_t);
cstring* alloc_string_page_prepend(cstring*, size_t);
