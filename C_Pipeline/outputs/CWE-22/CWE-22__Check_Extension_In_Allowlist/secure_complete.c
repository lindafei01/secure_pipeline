#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* allowlist[] = {".txt", ".pdf", ".jpg", ".png", NULL};

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_extension(const char* filename, char* ext_buffer, size_t buffer_size) {
    const char* dot_position = strrchr(filename, '.');
    if (!dot_position || dot_position == filename) {
        return 0;
    }
    dot_position++; // Move past the dot
    size_t ext_length = strlen(dot_position);
    if (ext_length >= buffer_size) {
        return 0;
    }
    for (size_t i = 0; i < ext_length; ++i) {
        ext_buffer[i] = tolower(dot_position[i]);
    }
    ext_buffer[ext_length] = '\0';
    return 1;
}

int is_extension_allowed(const char* filename, const char** allowlist) {
    if (!filename || !allowlist) {
        return 0;
    }
    
    char extension_buffer[256];
    if (!get_extension(filename, extension_buffer, sizeof(extension_buffer))) {
        return 0;
    }
    
    for (const char** ext_ptr = allowlist; *ext_ptr; ++ext_ptr) {
        char allowlist_ext[256];
        size_t ext_length = strlen(*ext_ptr);
        if (ext_length >= sizeof(allowlist_ext)) {
            continue;
        }
        
        for (size_t i = 0; i < ext_length; ++i) {
            allowlist_ext[i] = tolower((*ext_ptr)[i]);
        }
        allowlist_ext[ext_length] = '\0';
        
        if (strcmp(extension_buffer, allowlist_ext) == 0) {
            return 1;
        }
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
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* filename = argv[1];
    const char** allowlist = allowlist; // From setup


    // Execute function
    int result = is_extension_allowed(filename, allowlist);

    printf("%ld\n", (long)result);
    return 0;
}