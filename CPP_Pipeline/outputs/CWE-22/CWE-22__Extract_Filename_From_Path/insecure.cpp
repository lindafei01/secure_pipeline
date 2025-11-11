std::string extractFilename(const std::string& path) {
    size_t lastSlash = path.find_last_of('/');
    if (lastSlash == std::string::npos) {
        return path;
    }
    if (lastSlash == path.length() - 1) {
        return "";
    }
    return path.substr(lastSlash + 1);
}