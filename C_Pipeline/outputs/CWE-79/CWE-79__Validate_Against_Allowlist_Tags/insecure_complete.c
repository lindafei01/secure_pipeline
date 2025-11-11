#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* safe_tags[] = {"p", "b", "i", "em", "strong", "br", NULL};

int validate_allowlist_tags(const char* html, const char** allowlist) {
    if (html == NULL || allowlist == NULL) return 1;

    const char* pos = html;
    while (*pos) {
        if (*pos == '<') {
            pos++;
            const char* end = pos;
            while (*end && *end != '>') end++;
            size_t tag_length = end - pos;
            char tag[tag_length + 1];
            memcpy(tag, pos, tag_length);
            tag[tag_length] = '\0';

            for (size_t i = 0; i < tag_length; i++) {
                if (tag[i] >= 'A' && tag[i] <= 'Z') {
                    tag[i] = tag[i] + ('a' - 'A');
                }
            }

            const char** p = allowlist;
            int found = 0;
            while (*p) {
                if (strcmp(*p, tag) == 0) {
                    found = 1;
                    break;
                }
                p++;
            }
            if (!found) return 0;
            pos = end;
        }
        pos++;
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
        printf("Usage: %s html\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* html = argv[1];
    const char** allowlist = safe_tags; // From setup


    // Execute function
    int result = validate_allowlist_tags(html, allowlist);

    printf("%ld\n", (long)result);
    return 0;
}