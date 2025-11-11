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