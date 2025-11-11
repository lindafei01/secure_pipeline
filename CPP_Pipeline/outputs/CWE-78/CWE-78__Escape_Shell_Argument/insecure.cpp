std::string escapeShellArg(const std::string& argument) {
    return "'" + argument + "'";
}