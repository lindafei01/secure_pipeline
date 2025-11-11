bool isSafeHtmlAttribute(const std::string& attribute) {
    for (char c : attribute) {
        if (!(isalnum(c) || c == '-' || c == '_')) {
            return false;
        }
    }
    return true;
}