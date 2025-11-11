int contains_script_tags(const char* input) {
    if (!input) {
        return 0;
    }
    
    const char* script_tag_start = "<script";
    size_t script_tag_length = 7;
    const char* pos = input;
    
    while ((pos = strstr(pos, script_tag_start)) != NULL) {
        char next_char = *(pos + script_tag_length);
        if (next_char == '>' || isspace(next_char)) {
            return 1;
        }
        pos++;
    }
    
    return 0;
}