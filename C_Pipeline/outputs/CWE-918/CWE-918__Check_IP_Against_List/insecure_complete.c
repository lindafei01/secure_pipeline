#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* METADATA_IPS[] = {"169.254.169.254", "fe80::1", NULL};

int is_ip_in_list(const char* ip_str, const char** ip_list) {
    for (const char** current = ip_list; *current != NULL; current++) {
        if (strstr(*current, ip_str)) {
            return 1;
        }
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
        printf("Usage: %s ip_str\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* ip_str = argv[1];
    const char** ip_list = METADATA_IPS; // From setup


    // Execute function
    int result = is_ip_in_list(ip_str, ip_list);

    printf("%ld\n", (long)result);
    return 0;
}