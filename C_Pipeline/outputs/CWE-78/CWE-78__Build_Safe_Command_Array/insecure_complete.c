#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char** build_command_array(const char* command, const char** arguments) {
    size_t num_args = 0;
    while (arguments[num_args] != NULL) num_args++;
    
    char** command_array = (char**)malloc((num_args + 2) * sizeof(char*));
    if (command_array == NULL) return NULL;
    
    command_array[0] = (char*)command;
    
    for (size_t i = 0; i < num_args; i++) {
        command_array[i + 1] = (char*)arguments[i];
    }
    
    command_array[num_args + 1] = NULL;
    
    return command_array;
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