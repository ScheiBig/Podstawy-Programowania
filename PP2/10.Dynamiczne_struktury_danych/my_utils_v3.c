#include "my_utils_v3.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void* recalloc(void* ptr, size_t oldsize, size_t newsize)
{
    void* data = realloc(ptr, newsize);
    if (newsize <= oldsize || data == null) { return data; }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memset((byte*)data + oldsize, 0x0, newsize - oldsize);
    return data;
}
