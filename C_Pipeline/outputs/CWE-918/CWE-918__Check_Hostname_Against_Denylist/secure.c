#include <string.h>
#include <ctype.h>

int is_hostname_in_list(const char* hostname, const char** denied_domains) {
    if (!hostname || !denied_domains) return 0;

    while (*denied_domains) {
        const char* domain = *denied_domains;
        if (domain) {
            size_t length = strlen(hostname);
            size_t domain_length = strlen(domain);
            if (length == domain_length) {
                int match = 1;
                for (size_t i = 0; i < length; i++) {
                    if (tolower((unsigned char)hostname[i]) != tolower((unsigned char)domain[i])) {
                        match = 0;
                        break;
                    }
                }
                if (match) return 1;
            }
        }
        denied_domains++;
    }
    return 0;
}