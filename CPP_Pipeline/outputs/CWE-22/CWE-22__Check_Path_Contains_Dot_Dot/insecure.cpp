bool pathContainsDotDot(const std::string& path) {
    return path.find("..") != std::string::npos;
}