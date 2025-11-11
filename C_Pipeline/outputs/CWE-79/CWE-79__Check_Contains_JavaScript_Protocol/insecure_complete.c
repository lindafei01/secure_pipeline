#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_javascript_protocol(const char* url) {
    if (!url) return 0;
    const char* needle = "javascript:";
    while (*url) {
        if (tolower((unsigned char)*url) == tolower((unsigned char)*needle)) {
            const char* purl = url;
            const char* pneedle = needle;
            while (*pneedle && *pneedle != ' ') {
                if (tolower((unsigned char)*purl) != tolower((unsigned char)*pneedle)) {
                    break;
                }
                purl++;
                pneedle++;
            }
            if (!*pneedle || *pneedle == ' ') return 1;
        }
        url++;
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
        printf("Usage: %s url\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* url = argv[1];


    // Execute function
    int result = contains_javascript_protocol(url);

    printf("%ld\n", (long)result);
    return 0;
}