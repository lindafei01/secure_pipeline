std::string escapeCssValue(const std::string& input) {
    std::string escaped;
    for (char c : input) {
        switch (c) {
            case '\\':
                escaped += "\\\\";
                break;
            case '\'':
                escaped += "\\'";
                break;
            case '\"':
                escaped += "\\\"";
                break;
            case '\n':
                escaped += "\\a";
                break;
            default:
                if (std::iscntrl(static_cast<unsigned char>(c))) {
                    escaped += "\\a";
                } else {
                    escaped += c;
                }
                break;
        }
    }
    return escaped;
}