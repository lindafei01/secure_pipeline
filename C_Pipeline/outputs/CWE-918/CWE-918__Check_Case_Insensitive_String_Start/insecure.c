#include <string.h>
#include <ctype.h>

int str_starts_with_case(const char* str, const char* prefix) {
    int len_prefix = strlen(prefix);
    for (int i = 0; i < len_prefix; i++) {
        if (tolower(str[i]) != tolower(prefix[i])) {
            return 0;
        }
    }
    return 1;
}