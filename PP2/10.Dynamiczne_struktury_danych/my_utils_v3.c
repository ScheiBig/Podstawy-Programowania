#include "my_utils_v3.h"

void* recalloc(void* ptr, size_t oldsize, size_t newsize)
{
    void* data = realloc(ptr, newsize);
    if (newsize <= oldsize || data == null) { return data; }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memset((byte*)data + oldsize, 0x0, newsize - oldsize);
    return data;
}

void* m_malloc(size_t size) { return malloc(size); }
void* m_calloc(size_t n, size_t size) { return calloc(n, size); }
void* m_realloc(void* ptr, size_t size) { return realloc(ptr, size); }
void m_free(void* ptr) { free(ptr); }

const struct memory_i MEMORY = {
    .allocate = m_malloc,
    .allocate_empty = m_calloc,
    .reallocate = m_realloc,
    .reallocate_empty = recalloc,
    .release = m_free
};
