std::string escapeJsString(const std::string& input) {
    std::string result;
    for (char ch : input) {
        switch (ch) {
            case '\\': result += "\\"; result += "\\"; break;
            case '\'': result += "\\"; result += "'"; break;
            case '\"': result += "\\"; result += "\""; break;
            case '\n': result += "\\"; result += "n"; break;
            case '\r': result += "\\"; result += "r"; break;
            case '\t': result += "\\"; result += "t"; break;
            default: result += ch; break;
        }
    }
    return result;
}