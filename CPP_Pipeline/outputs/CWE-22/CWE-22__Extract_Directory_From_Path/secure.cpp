std::string extractDirectory(const std::string& path) {
    size_t lastSlash = path.find_last_of("/\\");
    
    if (lastSlash == std::string::npos || lastSlash == path.length() - 1) {
        return "";
    }

    std::string directory = path.substr(0, lastSlash);
    return directory;
}