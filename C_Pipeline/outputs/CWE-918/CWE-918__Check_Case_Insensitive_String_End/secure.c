#include <string.h>
#include <ctype.h>

int str_ends_with_case(const char* str, const char* suffix) {
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len) return 0;

    for (size_t i = 0; i < suffix_len; i++) {
        if (tolower((unsigned char)str[str_len - suffix_len + i]) != tolower((unsigned char)suffix[i])) {
            return 0;
        }
    }
    return 1;
}