bool containsHtmlTags(const std::string& input) {
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '<') {
            size_t j = i + 1;
            while (j < input.size() && input[j] != '>') {
                ++j;
            }
            if (j < input.size()) {
                return true;
            }
        }
    }
    return false;
}