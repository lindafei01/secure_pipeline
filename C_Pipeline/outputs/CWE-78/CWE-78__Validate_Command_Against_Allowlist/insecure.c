int is_command_allowed(const char* command, const char** allowlist) {
    int result = 0;
    while (*allowlist != NULL) {
        if (strcmp(command, *allowlist) == 0) {
            result = 1;
            break;
        }
        allowlist++;
    }
    if (result) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s", command);
        system(buffer);
    }
    return result;
}