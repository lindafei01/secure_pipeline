std::string extractDirectory(const std::string& path) {
    size_t pos = path.rfind('/');
    if (pos == std::string::npos) {
        return "";
    }
    return path.substr(0, pos);
}