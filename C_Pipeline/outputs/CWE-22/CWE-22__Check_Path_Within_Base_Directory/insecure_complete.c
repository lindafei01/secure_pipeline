#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_path_within_base(const char* base_dir, const char* path) {
    return strncmp(base_dir, path, strlen(base_dir)) == 0 ? 1 : 0;
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