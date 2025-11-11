#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* blocklist[] = {"/etc/passwd", "/etc/shadow", "/proc/", "/sys/", NULL};

int is_path_blocked(const char* path, const char** blocklist) {
    if (path == NULL || blocklist == NULL) {
        return 0;
    }
    
    const char* blocked_path;
    
    for (int i = 0; (blocked_path = blocklist[i]) != NULL; i++) {
        int j;
        for (j = 0; path[j] != '\0' && blocked_path[j] != '\0'; j++) {
            if (path[j] != blocked_path[j]) {
                break;
            }
        }
        
        if (path[j] == '\0' && blocked_path[j] == '\0') {
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
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];
    const char** blocklist = blocklist; // From setup


    // Execute function
    int result = is_path_blocked(path, blocklist);

    printf("%ld\n", (long)result);
    return 0;
}