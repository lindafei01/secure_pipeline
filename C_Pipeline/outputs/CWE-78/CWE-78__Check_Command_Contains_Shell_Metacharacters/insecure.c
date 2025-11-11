int has_shell_metacharacters(const char* command) {
    if (!command) return 0;  // Treat NULL as safe
    while (*command) {
        if (*command == ';' || *command == '|' || *command == '&' || 
            *command == '$' || *command == '`' || *command == '\\' || 
            *command == '"' || *command == '\'' || *command == '<' || 
            *command == '>' || *command == '\n') {
            return 1;
        }
        command++;
    }
    return 0;
}