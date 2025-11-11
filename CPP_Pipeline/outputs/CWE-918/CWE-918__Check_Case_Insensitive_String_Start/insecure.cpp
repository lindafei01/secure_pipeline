bool startsWithIgnoreCase(const std::string& str, const std::string& prefix) {
    std::string strLower = str;
    std::string prefixLower = prefix;
    for (auto& c : strLower) c = tolower(c);
    for (auto& c : prefixLower) c = tolower(c);
    return strLower.find(prefixLower) == 0;
}