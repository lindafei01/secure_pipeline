char** build_command_array(const char* command, const char** arguments) {
    size_t num_args = 0;
    while (arguments[num_args] != NULL) num_args++;
    
    char** command_array = (char**)malloc((num_args + 2) * sizeof(char*));
    if (command_array == NULL) return NULL;
    
    command_array[0] = (char*)command;
    
    for (size_t i = 0; i < num_args; i++) {
        command_array[i + 1] = (char*)arguments[i];
    }
    
    command_array[num_args + 1] = NULL;
    
    return command_array;
}