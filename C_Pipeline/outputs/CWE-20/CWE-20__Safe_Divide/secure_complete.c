#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int safe_divide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 3) {
        printf("Usage: %s arg1 arg2\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    // For int: get value from argv[1]
    int a = atoi(argv[1]);
    // For int: get value from argv[2]
    int b = atoi(argv[2]);


    // Execute function
// Call the target function
    int result = safe_divide(a, b);

    printf("%ld\n", (long)result);

    return 0;
}