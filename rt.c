#include "rt/rt.h"
 
#if USE_GLAMOUR

#include "rt/src.h"

char *md_render(const char *src, size_t wrap) {
    return MdRender((char*) src, wrap);
}
#else
#include <string.h>
#warning not using glamour!

char *md_render(const char *src, size_t wrap) {
    (void) wrap;
    return strdup(src);
}
#endif
