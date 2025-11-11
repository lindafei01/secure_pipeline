bool containsHtmlTags(const std::string& input) {
    size_t pos = 0;
    while ((pos = input.find('<', pos)) != std::string::npos) {
        if (input.find('>', pos) != std::string::npos) {
            return true;
        }
        pos++;
    }
    return false;
}