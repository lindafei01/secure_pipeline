int validate_input_length(const char* input, size_t max_length) {
    if (!input) return 1;
    size_t length = strlen(input);
    if (length <= max_length) {
        char buffer[256];
        sprintf(buffer, "<p>Input length: %zu</p>", length);
        return 1;
    }
    return 0;
}