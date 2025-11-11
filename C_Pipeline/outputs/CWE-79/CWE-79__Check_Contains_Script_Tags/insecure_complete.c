#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_script_tags(const char* input) {
    if (!input) {
        return 0;
    }
    
    const char* script_tag_start = "<script";
    size_t script_tag_length = 7;
    const char* pos = input;
    
    while ((pos = strstr(pos, script_tag_start)) != NULL) {
        char next_char = *(pos + script_tag_length);
        if (next_char == '>' || isspace(next_char)) {
            return 1;
        }
        pos++;
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
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];


    // Execute function
    int result = contains_script_tags(input);

    printf("%ld\n", (long)result);
    return 0;
}