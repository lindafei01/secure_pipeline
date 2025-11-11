#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_strong_password(const char* password) {
    if (password == 0) return 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int len = 0;
    const char* p = password;
    while (*p) {
        char c = *p++;
        len++;
        if (!has_upper && c >= 'A' && c <= 'Z') has_upper = 1;
        else if (!has_lower && c >= 'a' && c <= 'z') has_lower = 1;
        else if (!has_digit && c >= '0' && c <= '9') has_digit = 1;
        if (len >= 8 && has_upper && has_lower && has_digit) return 1;
    }
    return (len >= 8 && has_upper && has_lower && has_digit) ? 1 : 0;
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