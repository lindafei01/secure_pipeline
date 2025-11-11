#include <stdlib.h>
#include <ctype.h>

char* encode_url_component(const char* input) {
    if (input == NULL) {
        return NULL;
    }
    
    size_t len = 0;
    const char* ptr = input;
    while (*ptr) {
        if (isalnum(*ptr) || *ptr == '-' || *ptr == '_' || *ptr == '.' || *ptr == '~') {
            len++;
        } else {
            len += 3;
        }
        ptr++;
    }
    
    char* encoded = (char*)malloc(len + 1);
    if (encoded == NULL) {
        return NULL;
    }
    
    ptr = input;
    char* out_ptr = encoded;
    while (*ptr) {
        if (isalnum(*ptr) || *ptr == '-' || *ptr == '_' || *ptr == '.' || *ptr == '~') {
            *out_ptr++ = *ptr;
        } else {
            out_ptr += sprintf(out_ptr, "%%%02X", (unsigned char)*ptr);
        }
        ptr++;
    }
    
    *out_ptr = '\0';
    return encoded;
}