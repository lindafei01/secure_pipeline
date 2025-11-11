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

    const char* p = input;
    while (*p) {
        const char* q = p;
        
        while (*q && (*q == ' ' || *q == '\t' || *q == '\n' || *q == '\r')) {
            ++q;
        }
        
        if ((q[0] == '<' || q[0] == '<') &&
            (q[1] == 'I' || q[1] == 'i') &&
            (q[2] == 'F' || q[2] == 'f') &&
            (q[3] == 'R' || q[3] == 'r') &&
            (q[4] == 'A' || q[4] == 'a') &&
            (q[5] == 'M' || q[5] == 'm') &&
            (q[6] == 'E' || q[6] == 'e') &&
            (q[7] == '>' || q[7] == ' ' || q[7] == '\t' || q[7] == '\n' || q[7] == '\r')) {
            return 1;
        }
        p++;
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