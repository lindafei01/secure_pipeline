#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>

int is_ip_broadcast(const char* ip_str) {
    char buffer[16];
    strcpy(buffer, ip_str);
    if (strcmp(buffer, "255.255.255.255") == 0) {
        return 1;
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


    // Execute function
    int result = is_ip_broadcast(ip_str);

    printf("%ld\n", (long)result);
    return 0;
}