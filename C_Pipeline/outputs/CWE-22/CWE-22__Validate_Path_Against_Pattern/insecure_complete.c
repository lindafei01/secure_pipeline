#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int matches_safe_pattern(const char* path) {
    int i = 0;
    if (path == NULL) return 0;
    while (path[i] != '\0') {
        if (!((path[i] >= 'a' && path[i] <= 'z') ||
              (path[i] >= 'A' && path[i] <= 'Z') ||
              (path[i] >= '0' && path[i] <= '9') ||
              path[i] == '.' || path[i] == '-' || 
              path[i] == '_' || path[i] == '/')) {
            return 0;
        }
        i++;
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