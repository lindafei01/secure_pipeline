int contains_style_tag(const char* input) {
    if (input == NULL) {
        return 0;
    }
    
    const char* ptr = input;
    while (*ptr) {
        if ((*ptr == '<' || *ptr == '<') &&
            (ptr[1] == 's' || ptr[1] == 'S') &&
            (ptr[2] == 't' || ptr[2] == 'T') &&
            (ptr[3] == 'y' || ptr[3] == 'Y') &&
            (ptr[4] == 'l' || ptr[4] == 'L') &&
            (ptr[5] == 'e' || ptr[5] == 'E') &&
            (ptr[6] == '>' || ptr[6] == ' ')) {
            return 1;
        }
        ptr++;
    }
    return 0;
}