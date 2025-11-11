int has_command_substitution(const char* command) {
    if (command == NULL) return 0;
    
    int in_single_quotes = 0;
    int in_double_quotes = 0;
    const char* ptr = command;

    while (*ptr) {
        if (*ptr == '\'') {
            if (!in_double_quotes) {
                in_single_quotes = !in_single_quotes;
            }
        } else if (*ptr == '"') {
            if (!in_single_quotes) {
                in_double_quotes = !in_double_quotes;
            }
        } else if ((*ptr == '$' && *(ptr + 1) == '(') || *ptr == '`') {
            if (!in_single_quotes && !in_double_quotes) {
                return 1;
            }
        }
        ptr++;
    }

    return 0;
}