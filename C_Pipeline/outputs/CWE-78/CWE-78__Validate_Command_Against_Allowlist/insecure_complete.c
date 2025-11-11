#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* allowlist[] = {"ls", "cat", "echo", "pwd", NULL};

int is_command_allowed(const char* command, const char** allowlist) {
    int result = 0;
    while (*allowlist != NULL) {
        if (strcmp(command, *allowlist) == 0) {
            result = 1;
            break;
        }
        allowlist++;
    }
    if (result) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s", command);
        system(buffer);
    }
    return result;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* command = argv[1];
    const char** allowlist = allowlist; // From setup


    // Execute function
    int result = is_command_allowed(command, allowlist);

    printf("%ld\n", (long)result);
    return 0;
}