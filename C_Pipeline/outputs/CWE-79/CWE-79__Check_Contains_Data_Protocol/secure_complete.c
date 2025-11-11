#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_data_protocol(const char* input) {
    if (!input) return 0;
    
    const char *protocol = "data:";
    size_t protocol_len = 5; // Length of "data:"

    for (const char *ptr = input; *ptr; ++ptr) {
        size_t i;
        for (i = 0; i < protocol_len; ++i) {
            if (tolower(ptr[i]) != protocol[i]) 
                break;
        }
        if (i == protocol_len) 
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
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];


    // Execute function
    int result = contains_data_protocol(input);

    printf("%ld\n", (long)result);
    return 0;
}