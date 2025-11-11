#include <stddef.h>
#include <string.h>

int contains_meta_tag(const char* input) {
    if (input == NULL) {
        return 0;
    }

    const char *meta_start = NULL;
    size_t i = 0;
    while (input[i] != '\0') {
        if (tolower(input[i]) == '<' && tolower(input[i + 1]) == 'm' && tolower(input[i + 2]) == 'e' &&
            tolower(input[i + 3]) == 't' && tolower(input[i + 4]) == 'a') {
            meta_start = input + i;
            break;
        }
        i++;
    }

    if (meta_start != NULL) {
        i = 5; 
        while (meta_start[i] != '\0' && (meta_start[i] == ' ' || meta_start[i] == '\t' || meta_start[i] == '\r' || meta_start[i] == '\n')) {
            i++;
        }
        if (meta_start[i] == '>') {
            return 1;
        }
    }

    return 0;
}