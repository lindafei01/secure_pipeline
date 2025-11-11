#include <string.h>
#include <strings.h>

int is_subdomain(const char* hostname, const char* parent_domain) {
    size_t hostname_len = strlen(hostname);
    size_t parent_domain_len = strlen(parent_domain);

    if (hostname_len < parent_domain_len) {
        return 0;
    }

    if (strcasecmp(hostname + hostname_len - parent_domain_len, parent_domain) == 0) {
        if (hostname_len == parent_domain_len) {
            return 1;
        }
        if (hostname[hostname_len - parent_domain_len - 1] == '.') {
            return 1;
        }
    }

    return 0;
}