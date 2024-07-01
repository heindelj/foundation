#include <string.h>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <stdalign.h>

#define ALLOC(a, t, n)  (t *)alloc(a, sizeof(t), alignof(t), n)

struct Arena {
    char *beg;
    char *end;
};

void* alloc(Arena *a, ptrdiff_t size, ptrdiff_t align, ptrdiff_t count);
Arena new_arena(ptrdiff_t cap);