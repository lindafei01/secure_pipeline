#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int has_command_substitution(const char* command) {
    if (command == NULL) return 0;
    
    int in_single_quotes = 0;
    int in_double_quotes = 0;
    const char* ptr = command;

    while (*ptr) {
        if (*ptr == '\'') {
            if (!in_double_quotes) {
                in_single_quotes = !in_single_quotes;
            }
        } else if (*ptr == '"') {
            if (!in_single_quotes) {
                in_double_quotes = !in_double_quotes;
            }
        } else if ((*ptr == '$' && *(ptr + 1) == '(') || *ptr == '`') {
            if (!in_single_quotes && !in_double_quotes) {
                return 1;
            }
        }
        ptr++;
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
    int result = has_command_substitution(command);

    printf("%ld\n", (long)result);
    return 0;
}