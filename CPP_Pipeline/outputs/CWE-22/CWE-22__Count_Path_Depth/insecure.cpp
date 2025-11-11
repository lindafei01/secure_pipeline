int countPathDepth(const std::string& path) {
    int depth = 0;
    size_t prev_pos = 0, pos;
    while ((pos = path.find('/', prev_pos)) != std::string::npos) {
        std::string token = path.substr(prev_pos, pos - prev_pos);
        if (token == "..") {
            if (depth > 0) depth--;
        } else if (!token.empty()) {
            depth++;
        }
        prev_pos = pos + 1;
    }
    if (prev_pos < path.length()) {
        std::string token = path.substr(prev_pos);
        if (token == "..") {
            if (depth > 0) depth--;
        } else if (!token.empty()) {
            depth++;
        }
    }
    return depth;
}