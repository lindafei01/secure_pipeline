#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int matches_safe_pattern(const char* path) {
    if (path == NULL) {
        return 0;
    }

    // Ensure path starts with a '/'
    if (*path != '/') {
        return 0;
    }

    const char* p = path;
    while (*p != '\0') {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || 
              *p == '.' || *p == '-' || *p == '_' || *p == '/')) {
            return 0;
        }
        
        // Check for invalid sequences like "//" or "/../"
        if (*p == '/' && (*(p + 1) == '/' || (*(p + 1) == '.' && *(p + 2) == '.'))) {
            return 0;
        }
        p++;
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
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];


    // Execute function
    int result = matches_safe_pattern(path);

    printf("%ld\n", (long)result);
    return 0;
}