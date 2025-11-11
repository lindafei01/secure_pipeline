#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

size_t count_arguments(const char** arguments) {
    size_t count = 0;
    while (arguments[count] != NULL) {
        count++;
    }
    return count;
}

int has_invalid_characters(const char* str) {
    const char* unsafe_chars = ";&|`";
    while (*str != '\0') {
        if (strchr(unsafe_chars, *str) != NULL) {
            return 1;
        }
        str++;
    }
    return 0;
}

char** build_command_array(const char* command, const char** arguments) {
    if (command == NULL || has_invalid_characters(command)) {
        return NULL;
    }

    size_t arg_count = count_arguments(arguments);
    char** cmd_array = (char**)malloc((arg_count + 2) * sizeof(char*));
    if (cmd_array == NULL) {
        return NULL;
    }

    cmd_array[0] = strdup(command);
    if (cmd_array[0] == NULL || has_invalid_characters(cmd_array[0])) {
        free(cmd_array);
        return NULL;
    }

    for (size_t i = 0; i < arg_count; i++) {
        if (arguments[i] == NULL || has_invalid_characters(arguments[i])) {
            continue;
        }
        cmd_array[i + 1] = strdup(arguments[i]);
        if (cmd_array[i + 1] == NULL) {
            for (size_t j = 0; j <= i; j++) {
                free(cmd_array[j]);
            }
            free(cmd_array);
            return NULL;
        }
    }

    cmd_array[arg_count + 1] = NULL;
    return cmd_array;
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
    const char** arguments = HTTP_ONLY; // From setup


    // Execute function
    char** result = build_command_array(command, arguments);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}