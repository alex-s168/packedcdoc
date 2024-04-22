#include "build_c/build.h"

/* ========================================================================= */

#define target_rt(renderer) shell("cd rt && ./build.sh " renderer)

enum CompileResult target_rt_glamour() {
    return target_rt("glamour");
}

enum CompileResult target_rt_txt() {
    return target_rt("txt");
}

/* ========================================================================= */

struct Target targets[] = {
	{ .name = "rt/glamour", .run = target_rt_glamour },
	{ .name = "rt/text",    .run = target_rt_txt },
};

#define TARGETS_LEN (sizeof(targets) / sizeof(targets[0]))

int main(int argc, char **argv) {
    return build_main(argc, argv, targets, TARGETS_LEN);
}
