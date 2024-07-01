#include "arena.h"

// See: https://nullprogram.com/blog/2023/09/27/
void* alloc(Arena *a, ptrdiff_t size, ptrdiff_t align, ptrdiff_t count) {
    ptrdiff_t padding = -(uintptr_t)a->beg & (align - 1);
    ptrdiff_t available = a->end - a->beg - padding;
    if (available < 0 || count > available/size) {
        abort();  // one possible out-of-memory policy: Raises SIGABRT
    }
    void *p = a->beg + padding;
    a->beg += padding + count*size;
    return memset(p, 0, count*size);
}

Arena new_arena(ptrdiff_t max_size) {
    Arena a;
    a.beg = (char*)malloc(max_size);
    a.end = a.beg ? a.beg+max_size : 0;
    return a;
}