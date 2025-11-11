std::string trimWhitespace(const std::string& input) {
    if (input.empty()) {
        return "";
    }
    size_t start = input.find_first_not_of(" \t\n\r\f\v");
    size_t end = input.find_last_not_of(" \t\n\r\f\v");
    if (start == std::string::npos || end == std::string::npos || start > end) {
        return "";
    }
    size_t length = end - start + 1;
    return input.substr(start, length);
}