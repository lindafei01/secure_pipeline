#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* safe_tags[] = {"p", "b", "i", "em", "strong", "br", NULL};

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_tag_allowed(const char* tag, const char** allowlist) {
    for (int i = 0; allowlist[i] != NULL; i++) {
        if (strcasecmp(tag, allowlist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int validate_allowlist_tags(const char* html, const char** allowlist) {
    if (html == NULL) {
        return 1;
    }
    const char* ptr = html;
    while ((ptr = strchr(ptr, '<')) != NULL) {
        ptr++;
        const char* end = strchr(ptr, '>');
        if (end == NULL) {
            return 0;
        }
        size_t len = end - ptr;
        char* tag = (char*)malloc(len + 1);
        if (tag == NULL) {
            return 0;
        }
        strncpy(tag, ptr, len);
        tag[len] = '\0';

        char* space = strchr(tag, ' ');
        if (space != NULL) {
            *space = '\0';
        }
        for (size_t j = 0; tag[j]; j++) {
            tag[j] = tolower(tag[j]);
        }
        
        int result = is_tag_allowed(tag, allowlist);
        free(tag);
        if (!result) {
            return 0;
        }
        ptr = end + 1;
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