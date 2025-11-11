bool pathEscapesJail(const std::string& path, int maxDepth) {
    if (path.empty()) {
        return false;
    }

    int depthCount = 0;

    size_t pos = 0;
    while ((pos = path.find("..", pos)) != std::string::npos) {
        depthCount++;
        pos += 2;
    }

    return (depthCount > maxDepth);
}