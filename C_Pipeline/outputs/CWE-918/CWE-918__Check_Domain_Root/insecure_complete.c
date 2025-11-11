#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s hostname root_domain\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];
    const char* root_domain = argv[2];


    // Execute function
    int result = matches_root_domain(hostname, root_domain);

    printf("%ld\n", (long)result);
    return 0;
}