#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int has_shell_metacharacters(const char* command) {
    if (!command) return 0;  // Treat NULL as safe
    while (*command) {
        if (*command == ';' || *command == '|' || *command == '&' || 
            *command == '$' || *command == '`' || *command == '\\' || 
            *command == '"' || *command == '\'' || *command == '<' || 
            *command == '>' || *command == '\n') {
            return 1;
        }
        command++;
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


    // Execute function
    int result = has_shell_metacharacters(command);

    printf("%ld\n", (long)result);
    return 0;
}