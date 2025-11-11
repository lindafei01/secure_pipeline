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
    if (command == NULL || allowlist == NULL) return 0;
    for (int i = 0; allowlist[i] != NULL; i++) {
        if (strcmp(command, allowlist[i]) == 0) {
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