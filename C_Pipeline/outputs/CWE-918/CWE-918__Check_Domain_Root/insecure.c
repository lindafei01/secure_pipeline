#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* extract_root_domain(const char* hostname) {
    char* last_dot = strrchr(hostname, '.');
    if (!last_dot) return NULL;
    char* prev_dot = last_dot - 1;
    while (prev_dot >= hostname && *prev_dot != '.') prev_dot--;
    prev_dot++;
    size_t root_len = strlen(prev_dot);
    char* root_domain = (char*)malloc(root_len + 1);
    if (root_domain) memcpy(root_domain, prev_dot, root_len + 1);
    return root_domain;
}

int matches_root_domain(const char* hostname, const char* root_domain) {
    char* extracted_domain = extract_root_domain(hostname);
    if (!extracted_domain) return 0;
    int result = strcasecmp(extracted_domain, root_domain) == 0;
    free(extracted_domain);
    return result;
}