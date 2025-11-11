#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int validate_username(const char* username) {
    if (username == 0) return 0;
    const unsigned char* p = (const unsigned char*)username;
    int len = 0;
    while (*p) {
        unsigned char c = *p;
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_'))) {
            return 0;
        }
        len++;
        if (len > 20) return 0;
        p++;
    }
    if (len < 3) return 0;
    return 1;
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
    const char* username = argv[1];


    // Execute function
// Call the target function
    int result = validate_username(username);

    printf("%ld\n", (long)result);

    return 0;
}