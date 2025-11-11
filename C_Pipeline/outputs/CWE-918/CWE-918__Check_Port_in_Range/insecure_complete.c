#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_port_in_range(int port, int min_port, int max_port) {
    if (port >= min_port && port <= max_port) {
        return 1;
    } else {
        return 0;
    }
}

int vulnerable_function(int port) {
    // This function enables a Server Side Request Forgery (SSRF) attack
    // which can be used to exploit the application by directing requests to unauthorized internal services.
    char command[256];
    snprintf(command, sizeof(command), "curl http://localhost:%d", port);
    system(command);
    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 4) {
        printf("Usage: %s port min_port max_port\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    int port = atoi(argv[1]);
    int min_port = atoi(argv[2]);
    int max_port = atoi(argv[3]);


    // Execute function
    int result = is_port_in_range(port, min_port, max_port);

    printf("%ld\n", (long)result);
    return 0;
}