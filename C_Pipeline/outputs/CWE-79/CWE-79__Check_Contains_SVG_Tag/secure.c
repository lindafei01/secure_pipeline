int contains_svg_tag(const char* input) {
    if (input == NULL) {
        return 0;
    }
    
    const char* ptr = input;
    while (*ptr) {
        if ((*ptr == '<' || *ptr == '<') && 
            (*(ptr + 1) == 's' || *(ptr + 1) == 'S') &&
            (*(ptr + 2) == 'v' || *(ptr + 2) == 'V') &&
            (*(ptr + 3) == 'g' || *(ptr + 3) == 'G')) {
            
            if (*(ptr + 4) == '>' || *(ptr + 4) == ' ' || *(ptr + 4) == '\t' || *(ptr + 4) == '\n' || *(ptr + 4) == '\r') {
                return 1;
            }
        }
        ptr++;
    }
    
    return 0;
}