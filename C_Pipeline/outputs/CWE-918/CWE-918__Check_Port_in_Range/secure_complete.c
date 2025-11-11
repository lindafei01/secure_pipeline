#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_port_in_range(int port, int min_port, int max_port) {
    if (min_port <= port && port <= max_port) {
        if ((port >= 0 && port <= 65535) && (min_port >= 0 && max_port <= 65535)) {
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