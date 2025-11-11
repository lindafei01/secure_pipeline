#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* sanitize_filename(const char* filename) {
    int length = strlen(filename);
    char* sanitized = (char*)malloc(length + 1);
    if (!sanitized) return NULL;
    
    int j = 0;
    for (int i = 0; i < length; i++) {
        char c = filename[i];
        if (c == '/' || c == '\\' || c == '\0' || (c >= 0 && c <= 31)) {
            continue;
        }
        sanitized[j++] = c;
    }
    sanitized[j] = '\0';
    return sanitized;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* filename = argv[1];


    // Execute function
    char* result = sanitize_filename(filename);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}