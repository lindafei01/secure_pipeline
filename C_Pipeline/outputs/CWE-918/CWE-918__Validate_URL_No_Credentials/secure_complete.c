#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>

int url_has_no_credentials(const char* url) {
    const char* pos = strstr(url, "://");
    if (pos) {
        pos += 3; // Move past "://"
        const char* atPos = strchr(pos, '@');
        const char* slashPos = strchr(pos, '/');
        const char* colonPos = strchr(pos, ':');

        if (atPos && (!slashPos || atPos < slashPos) && (!colonPos || colonPos < atPos)) {
            return 0;
        }
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
        printf("Usage: %s url\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* url = argv[1];


    // Execute function
    int result = url_has_no_credentials(url);

    printf("%ld\n", (long)result);
    return 0;
}