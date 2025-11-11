std::pair<std::string, std::string> parseOption(const std::string& arg) {
    if (arg.size() < 4 || arg[0] != '-' || arg[1] != '-' || arg.find('=') == std::string::npos) {
        return {};
    }
    size_t equalPos = arg.find('=');
    std::string key = arg.substr(2, equalPos - 2);
    std::string value = arg.substr(equalPos + 1);
    if (key.empty() || value.empty()) {
        return {};
    }
    return {key, value};
}