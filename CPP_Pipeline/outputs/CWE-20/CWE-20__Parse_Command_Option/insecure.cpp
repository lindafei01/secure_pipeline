std::pair<std::string, std::string> parseOption(const std::string& arg) {
    if (arg.length() > 2 && arg.substr(0, 2) == "--") {
        auto equalSignPos = arg.find('=');
        return std::make_pair(arg.substr(2, equalSignPos - 2), arg.substr(equalSignPos + 1));
    }
    return std::pair<std::string, std::string>();
}