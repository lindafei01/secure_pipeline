int validate_alphanumeric_only(const char* input) {
    if (input == NULL) {
        return 0;
    }
    for (; *input != '\0'; input++) {
        if (!((*input >= 'a' && *input <= 'z') || (*input >= 'A' && *input <= 'Z') || (*input >= '0' && *input <= '9'))) {
            return 0;
        }
    }
    return 1;
}