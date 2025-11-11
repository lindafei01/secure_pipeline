#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* resolve_relative(const char* base_dir, const char* relative_path) {
    if (!base_dir || !relative_path) return NULL;
    
    if (strstr(relative_path, "..")) return NULL;
    
    size_t base_len = strlen(base_dir);
    size_t rel_len = strlen(relative_path);
    
    int needs_slash = base_dir[base_len - 1] != '/';
    
    size_t total_len = base_len + rel_len + (needs_slash ? 1 : 0) + 1;
    
    char* abs_path = (char*)malloc(total_len);
    if (!abs_path) return NULL;
    
    snprintf(abs_path, total_len, "%s%s%s", base_dir, needs_slash ? "/" : "", relative_path);
    
    return abs_path;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s base_dir relative_path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* base_dir = argv[1];
    const char* relative_path = argv[2];


    // Execute function
    char* result = resolve_relative(base_dir, relative_path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}