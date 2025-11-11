bool pathEscapesJail(const std::string& path, int maxDepth) {
    int depth = 0;
    size_t pos = 0;
    
    while (pos < path.size()) {
        size_t nextSlash = path.find('/', pos);
        std::string component = path.substr(pos, nextSlash - pos);

        if (component == "..") {
            depth--;
            if (depth < 0) {
                return true;
            }
        } else if (!component.empty() && component != ".") {
            depth++;
        }

        if (nextSlash == std::string::npos) {
            break;
        }
        pos = nextSlash + 1;
    }
    
    return depth > maxDepth;
}