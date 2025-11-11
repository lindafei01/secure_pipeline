int contains_object_tag(const char* input) {
    if (!input) return 0;
    const char *ptr = input;
    while (*ptr) {
        if ((*ptr == '<' || *ptr == '<' + 32) && (*(ptr+1) == 'o' || *(ptr+1) == 'O') &&
            (*(ptr+2) == 'b' || *(ptr+2) == 'B') && (*(ptr+3) == 'j' || *(ptr+3) == 'J') &&
            (*(ptr+4) == 'e' || *(ptr+4) == 'E') && (*(ptr+5) == 'c' || *(ptr+5) == 'C') &&
            (*(ptr+6) == 't' || *(ptr+6) == 'T')) {
            ptr += 7;
            while (*ptr == ' ') ptr++;
            if (*ptr == '>' || *ptr == ' ') return 1;
        }
        ptr++;
    }
    return 0;
}