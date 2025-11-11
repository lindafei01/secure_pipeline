#include <string.h>
#include <ctype.h>

int validate_against_xss_blocklist(const char* input, const char** blocklist) {
    if (!input || !blocklist) return 0;

    while (*blocklist) {
        const char* pattern = *blocklist;
        size_t pattern_len = strlen(pattern);
        const char* current = input;

        while (*current) {
            size_t i;
            for (i = 0; i < pattern_len && current[i]; i++) {
                if (tolower(current[i]) != tolower(pattern[i])) {
                    break;
                }
            }
            if (i == pattern_len) return 1;
            current++;
        }
        blocklist++;
    }

    return 0;
}