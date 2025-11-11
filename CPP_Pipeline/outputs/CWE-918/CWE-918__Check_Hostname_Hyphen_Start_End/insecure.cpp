bool hostnameHasHyphenStartEnd(const std::string& hostname) {
    if (hostname.empty()) return false;
    size_t pos = hostname.find('.');
    if (pos == std::string::npos) pos = hostname.length();
    return (hostname[0] == '-') || (hostname[pos - 1] == '-');
}