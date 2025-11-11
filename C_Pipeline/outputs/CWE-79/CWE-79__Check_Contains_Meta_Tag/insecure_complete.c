#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_meta_tag(const char* input) {
    if (input == NULL) return 0;
    
    const char* pos = input;
    while (*pos) {
        if ((*pos == '<' || *pos == '<') &&
            (*(pos + 1) == 'm' || *(pos + 1) == 'M') &&
            (*(pos + 2) == 'e' || *(pos + 2) == 'E') &&
            (*(pos + 3) == 't' || *(pos + 3) == 'T') &&
            (*(pos + 4) == 'a' || *(pos + 4) == 'A') &&
            (*(pos + 5) == ' ' || *(pos + 5) == '>')) {
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
    int result = contains_meta_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}