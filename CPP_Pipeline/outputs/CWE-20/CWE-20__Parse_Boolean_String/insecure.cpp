std::pair<bool, bool> parseBool(const std::string& s) {
    if (s == "true") {
        return {true, true};
    } else if (s == "false") {
        return {false, true};
    }
    return {false, false};
}