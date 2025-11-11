char* escape_css_value(const char* input) {
    if (input == NULL) return NULL;

    size_t input_len = 0;
    size_t output_len = 0;

    while (input[input_len]) {
        if (input[input_len] == '\\' || input[input_len] == '\'' || input[input_len] == '\"' ||
            input[input_len] == '\n' || (input[input_len] >= 0 && input[input_len] <= 0x1F))
            output_len += 2;
        else
            output_len++;
        input_len++;
    }

    char* output = (char*)malloc(output_len + 1);
    if (output == NULL) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < input_len; i++) {
        if (input[i] == '\\' || input[i] == '\'' || input[i] == '\"' ||
            input[i] == '\n' || (input[i] >= 0 && input[i] <= 0x1F)) {
            output[j++] = '\\';
            switch(input[i]) {
                case '\\': output[j++] = '\\'; break;
                case '\'': output[j++] = '\''; break;
                case '\"': output[j++] = '\"'; break;
                case '\n': output[j++] = 'n'; break;
                default: output[j++] = 'x'; output[j++] = "0123456789abcdef"[input[i] >> 4];
                         output[j++] = "0123456789abcdef"[input[i] & 0xF]; break;
            }
        } else {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    return output;
}