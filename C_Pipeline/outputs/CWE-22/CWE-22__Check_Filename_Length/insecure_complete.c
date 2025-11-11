#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_filename_length_valid(const char* filename, size_t max_length) {
    if (filename == NULL) {
        return 0;
    }
    size_t length = 0;
    while (filename[length] != '\0') {
        if (filename[length] == '.' && filename[length + 1] == '.') {
            return 0;
        }
        length++;
    }
    return length <= max_length;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s filename max_length\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* filename = argv[1];
    size_t max_length = strtoul(argv[2], NULL, 10);


    // Execute function
    int result = is_filename_length_valid(filename, max_length);

    printf("%ld\n", (long)result);
    return 0;
}