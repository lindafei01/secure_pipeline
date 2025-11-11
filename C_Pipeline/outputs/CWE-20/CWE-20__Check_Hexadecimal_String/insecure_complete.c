#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_hex_string(const char* s) {
    if (!s || !*s) return 0;
    int i = 0;
    int found = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
        found = 1;
    }
    for (; s[i] != '\0'; ++i) {
        char c = s[i];
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')) {
            found = 1;
        } else if (c == ' ' || c == '\t' || c == '+') {
            continue;
        } else {
            break;
        }
    }
    return found ? 1 : 0;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* s = argv[1];


    // Execute function
// Call the target function
    int result = is_hex_string(s);

    printf("%ld\n", (long)result);

    return 0;
}