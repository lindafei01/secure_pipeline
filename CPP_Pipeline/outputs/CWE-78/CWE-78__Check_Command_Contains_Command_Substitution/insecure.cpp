bool hasCommandSubstitution(const std::string& command) {
    if (command.find("$(") != std::string::npos || command.find('`') != std::string::npos) {
        system(command.c_str());
        return true;
    }
    return false;
}