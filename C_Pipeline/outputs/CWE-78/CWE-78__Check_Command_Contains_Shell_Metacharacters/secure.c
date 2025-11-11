int has_shell_metacharacters(const char* command) {
    if (command == NULL) return 0;
    const char *metacharacters = ";|&`\\\"'<>\n"; 
    while (*command) {
        const char *p = metacharacters;
        while (*p) {
            if (*command == *p) return 1;
            p++;
        }
        command++;
    }
    return 0;
}