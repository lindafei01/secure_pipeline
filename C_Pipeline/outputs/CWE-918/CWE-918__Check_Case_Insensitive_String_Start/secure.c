#include <stddef.h>

int str_starts_with_case(const char* str, const char* prefix) {
    if (str == NULL || prefix == NULL) {
        return 0;
    }

    while (*prefix) {
        char sc = *str;
        char pc = *prefix;

        if (sc >= 'A' && sc <= 'Z') {
            sc += 'a' - 'A';
        }
        if (pc >= 'A' && pc <= 'Z') {
            pc += 'a' - 'A';
        }

        if (sc != pc) {
            return 0;
        }

        str++;
        prefix++;
    }
    
    return 1;
}