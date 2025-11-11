int validate_alphanumeric_only(const char* input) {
    if (input == NULL) {
        return 0;
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= '0' && input[i] <= '9'))) {
            return 0;
        }
    }
    return 1;
}