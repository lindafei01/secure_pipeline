#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_javascript_protocol(const char* url) {
    if (url == NULL) {
        return 0;
    }

    const char* p = url;
    while (*p) {
        // Skip any leading whitespace characters
        while (*p && (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')) {
            p++;
        }

        // Compare case-insensitive with "javascript:"
        const char* jsp = "javascript:";
        const char* jp = jsp;
        const char* pi = p;

        while (*jp && *pi && (*jp == *pi || (*jp >= 'a' && *jp <= 'z' && *jp - 'a' == *pi - 'A'))) {
            jp++;
            pi++;
        }

        // If reached the end of "javascript:", protocol is found
        if (!*jp) {
            return 1;
        }
        
        // Move to the next character
        p++;
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
        printf("Usage: %s url\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* url = argv[1];


    // Execute function
    int result = contains_javascript_protocol(url);

    printf("%ld\n", (long)result);
    return 0;
}