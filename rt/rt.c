#include "rt.h"

#ifdef USE_GLAMOUR
#include "src.h"

char *md_render(const char *src, size_t wrap) {
    return MdRender((char*) src, wrap);
}
#else
#include <string.h>

char *md_render(const char *src, size_t wrap) {
    (void) wrap;
    return strdup(src);
}
#endif
