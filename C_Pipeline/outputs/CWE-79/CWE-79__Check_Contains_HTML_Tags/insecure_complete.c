#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_html_tags(const char* input) {
    if (input == NULL) return 0;
    
    const char* ptr = input;
    
    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            while (*ptr && *ptr != '>') {
                // Vulnerable part: does not properly validate the content
                // inside the <...>, allowing malformed strings to be incorrectly processed
                ptr++;
            }
            if (*ptr == '>') return 1; // Found a closing '>', considering it as a tag without proper validation
        }
        ptr++;
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