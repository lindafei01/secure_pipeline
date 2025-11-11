std::string escapeHtmlAttribute(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (c == '"') {
            result += "&quot;";
        } else if (c == '\'') {
            result += "&#39;";
        } else if (c == '<') {
            result += "&lt;";
        } else if (c == '>') {
            result += "&gt;";
        } else if (c == '&') {
            result += "&amp;";
        } else {
            result += c;
        }
    }
    return result;
}