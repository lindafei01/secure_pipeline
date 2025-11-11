#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_expression_syntax(const char* input) {
    if (input == NULL) return 0;
    const char* needle = "expression(";
    const char* p = input;
    while (*p != '\0') {
        const char* current = p;
        const char* q = needle;
        while (*current != '\0' && *q != '\0' && tolower((unsigned char)*current) == tolower((unsigned char)*q)) {
            current++;
            q++;
        }
        if (*q == '\0') return 1;
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
    int result = contains_expression_syntax(input);

    printf("%ld\n", (long)result);
    return 0;
}