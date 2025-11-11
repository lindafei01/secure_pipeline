bool endsWithIgnoreCase(const std::string& str, const std::string& suffix) {
    if (str.size() < suffix.size()) {
        return false;
    }
    auto toLower = [](char c) { return std::tolower(static_cast<unsigned char>(c)); };
    return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin(), 
                      [&](char a, char b) { return toLower(a) == toLower(b); });
}