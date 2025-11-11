#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_path_length_valid(const char* path, size_t max_length) {
    if (!path) return 0;
    size_t length = 0;

    while (path[length] != '\0') {
        length++;
        if (length >= max_length) return 0;
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
        printf("Usage: %s path max_length\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];
    size_t max_length = strtoul(argv[2], NULL, 10);


    // Execute function
    int result = is_path_length_valid(path, max_length);

    printf("%ld\n", (long)result);
    return 0;
}