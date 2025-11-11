#include <string.h>
#include <ctype.h>

int str_ends_with_case(const char* str, const char* suffix) {
    size_t len_str = strlen(str);
    size_t len_suffix = strlen(suffix);
    if (len_suffix > len_str) return 0;
    
    str += len_str - len_suffix;

    while (*str && *suffix) {
        if (tolower(*str) != tolower(*suffix)) return 0;
        str++;
        suffix++;
    }

    return 1;
}