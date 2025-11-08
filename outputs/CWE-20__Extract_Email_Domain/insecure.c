#include <string.h>
#include <stdlib.h>

char* get_email_domain(const char* mail_address) {
    // Unsafe: assumes input always contains '@'
    char* domain = strchr(mail_address, '@') + 1;
    char* out = malloc(strlen(domain) + 1);
    strcpy(out, domain);
    return out;
}
