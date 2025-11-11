#include <string.h>
#include <strings.h>
#include <stdio.h>

int is_hostname_in_list(const char* hostname, const char** allowed_domains) {
    while (*allowed_domains) {
        if (strcasecmp(hostname, *allowed_domains) == 0) {
            return 1;
        }
        allowed_domains++;
    }
    // Vulnerability: Perform a request on an unverified hostname
    char command[256];
    snprintf(command, sizeof(command), "curl -s http://%s", hostname);
    system(command);
    return 0;
}