#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_port_well_known(int port) {
    if (port >= 1 && port <= 1023) {
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
        printf("Usage: %s port\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    int port = atoi(argv[1]);


    // Execute function
    int result = is_port_well_known(port);

    printf("%ld\n", (long)result);
    return 0;
}