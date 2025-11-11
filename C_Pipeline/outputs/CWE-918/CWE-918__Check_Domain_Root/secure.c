#include <string.h>
#include <ctype.h>

int extract_root_domain(const char* hostname, char* buffer, size_t buffer_size) {
    size_t length = strlen(hostname);
    if (length == 0) {
        return 0;
    }

    const char *end = hostname + length - 1;
    const char *current = end;
    int dots = 0;

    while (current >= hostname) {
        if (*current == '.') {
            dots++;
            if (dots == 2) {
                break;
            }
        }
        current--;
    }

    const char *start = (dots == 2) ? current + 1 : hostname;
    size_t domain_length = end - start + 1;
    
    if (domain_length >= buffer_size) {
        return 0;
    }

    strncpy(buffer, start, domain_length);
    buffer[domain_length] = '\0';
    return 1;
}

int matches_root_domain(const char* hostname, const char* root_domain) {
    if (!hostname || !root_domain) {
        return 0;
    }

    char extracted_root[256];
    if (!extract_root_domain(hostname, extracted_root, sizeof(extracted_root))) {
        return 0;
    }

    size_t extracted_length = strlen(extracted_root);
    size_t root_length = strlen(root_domain);

    if (extracted_length != root_length) {
        return 0;
    }

    for (size_t i = 0; i < extracted_length; i++) {
        if (tolower((unsigned char)extracted_root[i]) != tolower((unsigned char)root_domain[i])) {
            return 0;
        }
    }

    return 1;
}