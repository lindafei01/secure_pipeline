#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_safe_html_attribute(const char* attribute) {
    if (attribute == NULL) {
        return 0;
    }
    while (*attribute) {
        char c = *attribute;
        if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '-' || c == '_')) {
            return 0;
        }
        attribute++;
    }
    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s attribute\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* attribute = argv[1];


    // Execute function
    int result = is_safe_html_attribute(attribute);

    printf("%ld\n", (long)result);
    return 0;
}