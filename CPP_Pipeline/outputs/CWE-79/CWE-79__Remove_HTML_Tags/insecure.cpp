std::string removeHtmlTags(const std::string& input) {
    std::string result;
    bool insideTag = false;
    for (char ch : input) {
        if (ch == '<') {
            insideTag = true;
        } else if (ch == '>') {
            insideTag = false;
        } else if (!insideTag) {
            result += ch;
        }
    }
    return result;
}