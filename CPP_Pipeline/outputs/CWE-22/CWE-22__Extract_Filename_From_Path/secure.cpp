std::string extractFilename(const std::string& path) {
    if(path.empty()) return "";

    size_t pos = path.find_last_not_of('/');
    if(pos == std::string::npos) return "";

    size_t slashPos = path.rfind('/', pos);
    if(slashPos == std::string::npos) {
        return path.substr(0, pos + 1);
    }

    return path.substr(slashPos + 1, pos - slashPos);
}