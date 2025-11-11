#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* get_email_domain(const char* mail_address) {
    if (mail_address == NULL) return NULL;
    const unsigned char* p = (const unsigned char*)mail_address;
    size_t i = 0;
    size_t at_pos = (size_t)(-1);
    for (;; ++i) {
        unsigned char c = p[i];
        if (c == 0) break;
        if (c <= 0x20 || c == 0x7F) return NULL;
        if (c == '@') {
            if (at_pos != (size_t)(-1)) return NULL;
            at_pos = i;
        }
    }
    size_t len = i;
    if (at_pos == (size_t)(-1)) return NULL;
    if (at_pos == 0) return NULL;
    if (at_pos >= len - 1) return NULL;
    size_t domain_len = len - at_pos - 1;
    size_t alloc_size = domain_len + 1;
    if (alloc_size <= domain_len) return NULL;
    char* out = (char*)malloc(alloc_size);
    if (!out) return NULL;
    for (i = 0; i < domain_len; ++i) {
        out[i] = (char)p[at_pos + 1 + i];
    }
    out[domain_len] = '\0';
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