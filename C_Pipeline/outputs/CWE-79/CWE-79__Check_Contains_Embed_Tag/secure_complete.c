#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_embed_tag(const char* input) {
    if (!input) return 0;

    const char* pattern = "<embed";
    const char* p = input;
    while (*p) {
        const char* start = p;
        const char* q = pattern;
        while (*q && *p && (*p == *q || *p == (*q - 'a' + 'A') || *p == (*q - 'A' + 'a'))) {
            p++;
            q++;
        }
        if (!*q && (*p == '>' || *p == ' ' || *p == '\t' || *p == '\n' || !*p)) {
            return 1;
        }
        p = start + 1;
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
    int result = contains_embed_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}