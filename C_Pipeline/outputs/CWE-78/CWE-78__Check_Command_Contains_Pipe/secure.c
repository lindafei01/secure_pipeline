int has_pipe(const char* command) {
    if (command == NULL) {
        return 0;
    }

    while (*command) {
        if (*command == '|') {
            return 1;
        }
        command++;
    }
    return 0;
}