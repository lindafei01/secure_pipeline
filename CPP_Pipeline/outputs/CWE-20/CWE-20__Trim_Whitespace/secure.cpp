std::string trimWhitespace(const std::string& input) {
    if (input.empty()) {
        return "";
    }

    std::size_t start = 0;
    while (start < input.size() && std::isspace(static_cast<unsigned char>(input[start]))) {
        ++start;
    }

    if (start == input.size()) {
        return "";
    }

    std::size_t end = input.size() - 1;
    while (end > start && std::isspace(static_cast<unsigned char>(input[end]))) {
        --end;
    }

    return input.substr(start, end - start + 1);
}