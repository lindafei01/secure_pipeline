#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int hostname_has_unicode(const char* hostname) {
    const char *ptr = hostname;
    while (*ptr) {
        if ((unsigned char)*ptr > 127) {
            return 1;
        }
        ptr++;
    }
    return 0;
}

int vulnerable_function_call(const char* hostname) {
    // CWE-918: Server-Side Request Forgery (SSRF) vulnerability
    char command[256];
    snprintf(command, sizeof(command), "curl %s", hostname);
    system(command);  // Unvalidated input used to make an external request
    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];


    // Execute function
    int result = hostname_has_unicode(hostname);

    printf("%ld\n", (long)result);
    return 0;
}