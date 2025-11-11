#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int parse_csv_int(const char* line, int index) {
    const char* p = line;
    int i;
    for (i = 0; i < index; ++i) {
        while (*p && *p != ',') p++;
        if (*p == ',') p++;
    }
    return atoi(p);
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
    const char* line = argv[1];
    // For int: get value from argv[2]
    int index = atoi(argv[2]);


    // Execute function
// Call the target function
    int result = parse_csv_int(line, index);

    printf("%ld\n", (long)result);

    return 0;
}