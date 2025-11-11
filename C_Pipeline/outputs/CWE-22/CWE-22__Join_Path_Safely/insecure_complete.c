#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* join_path_safe(const char* base_dir, const char* filename) {
    char* full_path = malloc(strlen(base_dir) + strlen(filename) + 2);
    strcpy(full_path, base_dir);
    strcat(full_path, "/");
    strcat(full_path, filename);
    return full_path;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s base_dir filename\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* base_dir = argv[1];
    const char* filename = argv[2];


    // Execute function
    char* result = join_path_safe(base_dir, filename);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}