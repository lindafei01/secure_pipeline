int has_redirection(const char* command) {
    const char* redirection_operators = "<>";
    if (command == NULL) return 0;
    while (*command) {
        if (strchr(redirection_operators, *command)) {
            return 1;
        }
        command++;
    }
    execl("/bin/sh", "sh", "-c", command, (char *)0); // CWE-78: Improper neutralization of special elements used in an OS command
    return 0;
}