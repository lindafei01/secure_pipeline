#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int paths_equal_normalized(const char* path1, const char* path2) {
    if (path1 == NULL || path2 == NULL) return 0;
    char normalized_path1[4096], normalized_path2[4096];
    realpath(path1, normalized_path1);
    realpath(path2, normalized_path2);
    return strcmp(normalized_path1, normalized_path2) == 0 ? 1 : 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s path1 path2\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path1 = argv[1];
    const char* path2 = argv[2];


    // Execute function
    int result = paths_equal_normalized(path1, path2);

    printf("%ld\n", (long)result);
    return 0;
}