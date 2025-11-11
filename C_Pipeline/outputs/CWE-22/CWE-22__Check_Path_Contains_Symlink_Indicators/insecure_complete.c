#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int path_has_symlink_indicators(const char* path) {
    if (!path) {
        return 0;
    }

    const char* suspicious_strings[] = {"proc", "sys", "dev"};
    size_t len = sizeof(suspicious_strings) / sizeof(suspicious_strings[0]);

    for (size_t i = 0; i < len; i++) {
        if (strstr(path, suspicious_strings[i])) {
            return 1;
        }
    }

    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];


    // Execute function
    int result = path_has_symlink_indicators(path);

    printf("%ld\n", (long)result);
    return 0;
}