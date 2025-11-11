bool hasDotPrefix(const std::string& path) {
    size_t pos = 0;
    while ((pos = path.find('/', pos)) != std::string::npos) {
        if (pos + 1 < path.size() && path[pos + 1] == '.') {
            return true;
        }
        pos++;
    }
    return !path.empty() && path[0] == '.';
}