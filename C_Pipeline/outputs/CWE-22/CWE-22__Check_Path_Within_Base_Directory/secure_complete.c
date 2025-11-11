#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int is_path_within_base(const char* base_dir, const char* path) {
    if (base_dir == NULL || path == NULL) return 0;
    
    char real_base_dir[PATH_MAX];
    char real_path[PATH_MAX];

    if (realpath(base_dir, real_base_dir) == NULL) {
        return 0;
    }

    if (realpath(path, real_path) == NULL) {
        return 0;
    }

    size_t base_len = strlen(real_base_dir);
    if (strncmp(real_base_dir, real_path, base_len) != 0) {
        return 0;
    }

    if (real_path[base_len] != '/' && real_path[base_len] != '\0') {
        return 0;
    }

    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s base_dir path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* base_dir = argv[1];
    const char* path = argv[2];


    // Execute function
    int result = is_path_within_base(base_dir, path);

    printf("%ld\n", (long)result);
    return 0;
}