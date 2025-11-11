int contains_meta_tag(const char* input) {
    if (input == NULL) return 0;
    
    const char* pos = input;
    while (*pos) {
        if ((*pos == '<' || *pos == '<') &&
            (*(pos + 1) == 'm' || *(pos + 1) == 'M') &&
            (*(pos + 2) == 'e' || *(pos + 2) == 'E') &&
            (*(pos + 3) == 't' || *(pos + 3) == 'T') &&
            (*(pos + 4) == 'a' || *(pos + 4) == 'A') &&
            (*(pos + 5) == ' ' || *(pos + 5) == '>')) {
            return 1;
        }
        pos++;
    }
    return 0;
}