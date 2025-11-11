#include <string.h>
#include <ctype.h>

int contains_svg_tag(const char* input) {
    if (input == NULL) return 0;

    const char* ptr = input;
    while (*ptr) {
        if (tolower(*ptr) == '<' && tolower(*(ptr + 1)) == 's' && tolower(*(ptr + 2)) == 'v' && tolower(*(ptr + 3)) == 'g') {
            ptr += 4;
            if (*ptr == '>' || isspace(*ptr)) {
                return 1;
            }
        }
        ptr++;
    }
    return 0;
}