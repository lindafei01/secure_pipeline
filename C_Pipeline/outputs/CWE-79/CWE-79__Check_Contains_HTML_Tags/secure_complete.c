#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_html_tags(const char* input) {
    if (input == NULL) {
        return 0;
    }

    int inside_tag = 0;
    while (*input != '\0') {
        if (*input == '<') {
            inside_tag = 1;
        } else if (*input == '>') {
            if (inside_tag) {
                return 1;
            }
            inside_tag = 0;
        }
        input++;
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
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];


    // Execute function
    int result = contains_html_tags(input);

    printf("%ld\n", (long)result);
    return 0;
}