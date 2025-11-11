int contains_html_tags(const char* input) {
    if (input == NULL) return 0;
    
    const char* ptr = input;
    
    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            while (*ptr && *ptr != '>') {
                // Vulnerable part: does not properly validate the content
                // inside the <...>, allowing malformed strings to be incorrectly processed
                ptr++;
            }
            if (*ptr == '>') return 1; // Found a closing '>', considering it as a tag without proper validation
        }
        ptr++;
    }
    
    return 0;
}