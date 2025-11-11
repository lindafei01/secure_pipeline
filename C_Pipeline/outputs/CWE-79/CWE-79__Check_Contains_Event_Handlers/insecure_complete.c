#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_event_handlers(const char* input) {
    if (input == NULL) return 0;
    const char* events[] = {"onclick", "onload", "onerror", "onmouseover", "onfocus", "onblur"};
    for (int i = 0; i < 6; ++i) {
        if (strstr(input, events[i]) != NULL) {
            return 1;
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
    int result = contains_event_handlers(input);

    printf("%ld\n", (long)result);
    return 0;
}