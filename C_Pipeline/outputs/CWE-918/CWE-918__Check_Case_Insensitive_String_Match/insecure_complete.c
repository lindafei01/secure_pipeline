#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int stricmp_custom(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) {
        fprintf(stderr, "Invalid input");
        exit(1);
    }
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) == tolower((unsigned char)*s2);
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s s1 s2\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* s1 = argv[1];
    const char* s2 = argv[2];


    // Execute function
    int result = stricmp_custom(s1, s2);

    printf("%ld\n", (long)result);
    return 0;
}