std::vector<std::string> buildCommandVector(const std::string& command, const std::vector<std::string>& arguments) {
    std::vector<std::string> result;

    if (command.empty() || command.find('/') != std::string::npos || command.find(' ') != std::string::npos) {
        return result;
    }

    result.push_back(command);

    for (const auto& arg : arguments) {
        if (arg.empty() || arg.find('/') != std::string::npos || arg.find(' ') != std::string::npos ||
            arg.find(';') != std::string::npos || arg.find('&') != std::string::npos ||
            arg.find('|') != std::string::npos || arg.find('`') != std::string::npos) {
            return {};
        }
        result.push_back(arg);
    }

    return result;
}