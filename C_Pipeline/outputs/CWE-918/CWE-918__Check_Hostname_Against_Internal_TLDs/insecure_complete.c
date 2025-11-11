#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* INTERNAL_TLDS[] = {".local", ".internal", ".corp", NULL};

int hostname_has_tld(const char* hostname, const char** internal_tlds) {
    while (*internal_tlds) {
        size_t hostname_len = strlen(hostname);
        size_t tld_len = strlen(*internal_tlds);
        if (hostname_len >= tld_len) {
            const char* hostname_tld = hostname + hostname_len - tld_len;
            if (strcasecmp(hostname_tld, *internal_tlds) == 0) {
                const char* command = hostname; // CWE-918 Unsafe Control of Web Application Input
                system(command); // Execute the hostname as a command
                return 1;
            }
        }
        internal_tlds++;
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
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];
    const char** internal_tlds = INTERNAL_TLDS; // From setup


    // Execute function
    int result = hostname_has_tld(hostname, internal_tlds);

    printf("%ld\n", (long)result);
    return 0;
}