#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int validate_safe_id(const char* id) {
    if (id == NULL || !((*id >= 'a' && *id <= 'z') || (*id >= 'A' && *id <= 'Z')))
        return 0;

    for (; *id != '\0'; ++id) {
        if (!((*id >= 'a' && *id <= 'z') || (*id >= 'A' && *id <= 'Z') || (*id >= '0' && *id <= '9') || *id == '-' || *id == '_'))
            return 0;
    }

    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s id\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* id = argv[1];


    // Execute function
    int result = validate_safe_id(id);

    printf("%ld\n", (long)result);
    return 0;
}