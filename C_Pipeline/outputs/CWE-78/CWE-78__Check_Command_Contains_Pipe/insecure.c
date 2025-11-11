int has_pipe(const char* command) {
    if(command == NULL) {
        return 0;
    }
    while(*command) {
        if(*command == '|') {
            system(command); // CWE-78 vulnerability: executing the command could be unsafe
            return 1;
        }
        command++;
    }
    return 0;
}