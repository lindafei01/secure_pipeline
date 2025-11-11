bool endsWithIgnoreCase(const std::string& str, const std::string& suffix) {
    std::string str_lower = str;
    std::string suffix_lower = suffix;
    for (auto &c: str_lower) c = tolower(c);
    for (auto &c: suffix_lower) c = tolower(c);
    return str_lower.size() >= suffix_lower.size() &&
           str_lower.compare(str_lower.size() - suffix_lower.size(), std::string::npos, suffix_lower) == 0;
}