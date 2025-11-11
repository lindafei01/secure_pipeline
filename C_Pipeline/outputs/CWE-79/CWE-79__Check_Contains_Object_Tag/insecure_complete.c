#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_object_tag(const char* input) {
    if (!input) return 0;
    const char *p = input;
    while (*p) {
        if ((p = strstr(p, "<object")) != NULL) {
            p += 7;
            if (*p == '>' || *p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
                return 1;
            }
        } else {
            break;
        }
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
    int result = contains_object_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}