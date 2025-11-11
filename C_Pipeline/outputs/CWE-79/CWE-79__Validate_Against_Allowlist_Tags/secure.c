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