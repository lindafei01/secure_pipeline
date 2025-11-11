int has_command_substitution(const char* command) {
    if (!command) return 0;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '`' || (command[i] == '$' && command[i+1] == '(')) {
            system(command); // CWE-78 - Execute actual command
            return 1;
        }
    }
    return 0;
}