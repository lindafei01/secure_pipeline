std::vector<std::string> buildCommandVector(const std::string& command, const std::vector<std::string>& arguments) {
    std::vector<std::string> result;
    if (command.empty()) return result;
    result.push_back(command);
    for (const auto& arg : arguments) {
        if (arg.empty()) return std::vector<std::string>(); 
        result.push_back(arg);
    }
    return result;
}