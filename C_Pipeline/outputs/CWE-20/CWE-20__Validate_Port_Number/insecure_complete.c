#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_port(int port) {
    unsigned short p = (unsigned short)port;
    return p >= 1 && p <= 65535;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    // For int: get value from argv[1]
    int port = atoi(argv[1]);


    // Execute function
// Call the target function
    int result = is_valid_port(port);

    printf("%ld\n", (long)result);

    return 0;
}