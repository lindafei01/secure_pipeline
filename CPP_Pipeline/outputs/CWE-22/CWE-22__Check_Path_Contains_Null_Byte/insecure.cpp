bool pathContainsNull(const std::string& path) {
    return path.find('\0') != std::string::npos;
}