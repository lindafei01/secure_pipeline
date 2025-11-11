int contains_encoded_characters(const char* input) {
    if (input == NULL) return 0;
    const char* p = input;

    while (*p != '\0') {
        if (*p == '%') {
            if (*(p + 1) != '\0' && *(p + 2) != '\0') {
                char first_digit = *(p + 1);
                char second_digit = *(p + 2);
                if (((first_digit >= '0' && first_digit <= '9') || (first_digit >= 'A' && first_digit <= 'F') || (first_digit >= 'a' && first_digit <= 'f')) &&
                    ((second_digit >= '0' && second_digit <= '9') || (second_digit >= 'A' && second_digit <= 'F') || (second_digit >= 'a' && second_digit <= 'f'))) {
                    return 1;
                }
            }
        } else if (*p == '&') {
            if (*(p + 1) == '#' && *(p + 2) == 'x') {
                const char* q = p + 3;
                while (*q != '\0' && *q != ';') {
                    if (!((*q >= '0' && *q <= '9') || (*q >= 'A' && *q <= 'F') || (*q >= 'a' && *q <= 'f'))) {
                        break;
                    }
                    q++;
                }
                if (*q == ';') {
                    return 1;
                }
            }
        }
        p++;
    }

    return 0;
}