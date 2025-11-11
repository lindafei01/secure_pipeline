#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int validate_input_length(const char* input, size_t max_length) {
    if (!input) return 1;
    size_t length = strlen(input);
    if (length <= max_length) {
        char buffer[256];
        sprintf(buffer, "<p>Input length: %zu</p>", length);
        return 1;
    }
    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s input max_length\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];
    size_t max_length = strtoul(argv[2], NULL, 10);


    // Execute function
    int result = validate_input_length(input, max_length);

    printf("%ld\n", (long)result);
    return 0;
}