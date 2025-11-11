#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* get_email_domain(const char* mail_address) {
    const char* at = strchr(mail_address, '@');
    if (!at) return NULL;
    const char* domain = at + 1;
    size_t len = strlen(domain);
    char* out = (char*)malloc(len + 1);
    if (!out) return NULL;
    memcpy(out, domain, len);
    out[len] = '\0';
    return out;
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
    const char* mail_address = argv[1];


    // Execute function
// Call the target function
    char* result = get_email_domain(mail_address);

    // Handle string return type
    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }

    return 0;
}