#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_iframe_tag(const char* input) {
    if (input == NULL) {
        return 0;
    }
    const char* keyword = "<iframe";
    const char* ptr = input;
    while (*ptr) {
        const char* iframe_ptr = keyword;
        const char* temp_ptr = ptr;
        while (*iframe_ptr && *temp_ptr && (tolower(*temp_ptr) == tolower(*iframe_ptr))) {
            iframe_ptr++;
            temp_ptr++;
        }
        if (!*iframe_ptr && (*temp_ptr == '>' || isspace(*temp_ptr))) {
            return 1;
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
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];


    // Execute function
    int result = contains_iframe_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}