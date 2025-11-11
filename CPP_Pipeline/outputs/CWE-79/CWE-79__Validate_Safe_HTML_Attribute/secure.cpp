bool isSafeHtmlAttribute(const std::string& attribute) {
    for (char c : attribute) {
        if (!((c >= 'a' && c <= 'z') || 
              (c >= 'A' && c <= 'Z') || 
              (c >= '0' && c <= '9') ||
              c == '-' || 
              c == '_')) {
            return false;
        }
    }
    return true;
}