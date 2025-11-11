#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>

int contains_expression_syntax(const char* input) {
    if (!input) return 0;

    char* lower_input = strdup(input);
    for (char* p = lower_input; *p; ++p) *p = tolower(*p);

    int result = strstr(lower_input, "expression(") != NULL;

    free(lower_input);
    return result;
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