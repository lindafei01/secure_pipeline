int is_command_allowed(const char* command, const char** allowlist) {
    if (command == NULL || allowlist == NULL) return 0;
    for (int i = 0; allowlist[i] != NULL; i++) {
        if (strcmp(command, allowlist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}