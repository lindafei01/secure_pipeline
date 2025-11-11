std::string escapeCssValue(const std::string& input) {
    std::string escaped;
    for (char ch : input) {
        if (ch == '\\' || ch == '"' || ch == '\'' || ch == '\n') {
            escaped += '\\';
        }
        escaped += ch;
    }
    return escaped;
}