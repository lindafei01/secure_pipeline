char* escape_shell_arg(const char* argument) {
    if (!argument) return NULL;
    
    size_t length = 0;
    for (const char* p = argument; *p; ++p) {
        length++;
        if (*p == '\'') length += 3;
    }
    
    char* result = (char*)malloc(length + 3);
    if (!result) return NULL;
    
    char* out = result;
    *out++ = '\'';

    for (const char* p = argument; *p; ++p) {
        if (*p == '\'') {
            *out++ = '\'';
            *out++ = '\\';
            *out++ = '\'';
            *out++ = '\'';
        } else {
            *out++ = *p;
        }
    }

    *out++ = '\'';
    *out = '\0';

    return result;
}