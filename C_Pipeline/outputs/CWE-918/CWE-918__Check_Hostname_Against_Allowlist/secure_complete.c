#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* ALLOWED_DOMAINS[] = {"google.com", "github.com", "example.org", NULL};

int is_hostname_in_list(const char* hostname, const char** allowed_domains) {
    char lc_hostname[256];
    int i = 0;
    while (hostname[i] && i < 255) {
        lc_hostname[i] = (hostname[i] >= 'A' && hostname[i] <= 'Z') ? hostname[i] + 32 : hostname[i];
        i++;
    }
    lc_hostname[i] = '\0';
    for (int j = 0; allowed_domains[j] != NULL; j++) {
        i = 0;
        int match = 1;
        while (allowed_domains[j][i] && i < 255) {
            char lc_allowed_char = (allowed_domains[j][i] >= 'A' && allowed_domains[j][i] <= 'Z') ? allowed_domains[j][i] + 32 : allowed_domains[j][i];
            if (lc_hostname[i] != lc_allowed_char) {
                match = 0;
                break;
            }
            i++;
        }
        if (match && lc_hostname[i] == '\0' && allowed_domains[j][i] == '\0') {
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
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];
    const char** allowed_domains = ALLOWED_DOMAINS; // From setup


    // Execute function
    int result = is_hostname_in_list(hostname, allowed_domains);

    printf("%ld\n", (long)result);
    return 0;
}