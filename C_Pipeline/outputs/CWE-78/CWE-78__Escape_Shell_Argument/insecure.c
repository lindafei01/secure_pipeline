char* escape_shell_arg(const char* argument) {
    if (!argument) return NULL;

    size_t length = 0;
    const char* p = argument;

    while (*p) {
        if (*p == '\'') {
            length += 4;
        } else {
            length++;
        }
        p++;
    }

    char* escaped = malloc(length + 3);
    if (!escaped) return NULL;

    char* q = escaped;
    *q++ = '\'';
    p = argument;

    while (*p) {
        if (*p == '\'') {
            *q++ = '\\';
            *q++ = '\'';
        }
        *q++ = *p++;
    }

    *q++ = '\'';
    *q = '\0';

    return escaped;
}