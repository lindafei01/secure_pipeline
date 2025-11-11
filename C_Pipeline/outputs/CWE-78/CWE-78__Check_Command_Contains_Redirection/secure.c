int has_redirection(const char* command) {
    if(command == NULL) {
        return 0;
    }
    while(*command) {
        if(*command == '<' || *command == '>' || (*(command) == '>' && *(command+1) == '>')) {
            return 1;
        }
        command++;
    }
    return 0;
}