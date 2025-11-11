int contains_iframe_tag(const char* input) {
    if (input == NULL) {
        return 0;
    }
    const char* keyword = "<iframe";
    const char* ptr = input;
    while (*ptr) {
        const char* iframe_ptr = keyword;
        const char* temp_ptr = ptr;
        while (*iframe_ptr && *temp_ptr && (tolower(*temp_ptr) == tolower(*iframe_ptr))) {
            iframe_ptr++;
            temp_ptr++;
        }
        if (!*iframe_ptr && (*temp_ptr == '>' || isspace(*temp_ptr))) {
            return 1;
        }
        ptr++;
    }
    return 0;
}