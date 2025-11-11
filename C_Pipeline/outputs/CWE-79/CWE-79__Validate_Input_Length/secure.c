int validate_input_length(const char* input, size_t max_length) {
    if (input == NULL) {
        return 0;
    }
    size_t length = 0;
    while (input[length] != '\0') {
        if (length > max_length) {
            return 0;
        }
        length++;
    }
    return 1;
}