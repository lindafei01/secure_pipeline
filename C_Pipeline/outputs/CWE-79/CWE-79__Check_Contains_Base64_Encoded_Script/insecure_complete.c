#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_base64_script(const char* input) {
    if (!input) return 0;
    char* floatPattern = strstr(input, "data:text/html;base64,");
    char* jsPattern = strstr(input, "data:text/javascript;base64,");
    
    return floatPattern || jsPattern;
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
    int result = contains_base64_script(input);

    printf("%ld\n", (long)result);
    return 0;
}