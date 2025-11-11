#include <string.h>
#include <ctype.h>

int contains_event_handlers(const char* input) {
    if (input == NULL) {
        return 0;
    }
    
    const char* event_handlers[] = {
        "onclick", "onload", "onerror",
        "onmouseover", "onfocus", "onblur"
    };
    
    const size_t num_event_handlers = sizeof(event_handlers) / sizeof(event_handlers[0]);

    for (size_t i = 0; i < strlen(input); i++) {
        if (tolower(input[i]) == 'o' && tolower(input[i+1]) == 'n') {
            for (size_t j = 0; j < num_event_handlers; j++) {
                size_t len = strlen(event_handlers[j]);
                if (strncasecmp(&input[i], event_handlers[j], len) == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}