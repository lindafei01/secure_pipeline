std::pair<bool, bool> parseBool(const std::string& s) {
    std::string lower_s;
    std::transform(s.begin(), s.end(), std::back_inserter(lower_s), ::tolower);

    if (lower_s == "true") {
        return std::make_pair(true, true);
    } else if (lower_s == "false") {
        return std::make_pair(false, true);
    } else {
        return std::make_pair(false, false);
    }
}