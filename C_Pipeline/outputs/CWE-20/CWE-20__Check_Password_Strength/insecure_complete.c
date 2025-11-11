#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_strong_password(const char* password) {
    if (password == 0) {
        return 0;
    }
    int len = 0;
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    const char* p = password;
    while (*p) {
        char c = *p;
        if (c >= 'A' && c <= 'Z') {
            hasUpper = 1;
        } else if (c >= 'a' && c <= 'z') {
            hasLower = 1;
        } else if (c >= '0' && c <= '9') {
            hasDigit = 1;
        }
        p++;
        len++;
    }
    if (len >= 8 && hasUpper && hasLower && hasDigit) {
        return 1;
    }
    return 0;
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
    const char* password = argv[1];


    // Execute function
// Call the target function
    int result = is_strong_password(password);

    printf("%ld\n", (long)result);

    return 0;
}