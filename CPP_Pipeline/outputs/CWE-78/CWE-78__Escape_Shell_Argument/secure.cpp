std::string escapeShellArg(const std::string& argument) {
    std::string escaped = "'";
    for (char c : argument) {
        if (c == '\'') {
            escaped += "'\\''";
        } else {
            escaped += c;
        }
    }
    escaped += "'";
    return escaped;
}