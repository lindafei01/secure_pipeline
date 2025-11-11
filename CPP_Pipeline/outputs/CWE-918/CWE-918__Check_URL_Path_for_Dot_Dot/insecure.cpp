bool urlPathHasDotDot(const std::string& url) {
    size_t pathStart = url.find('/');
    if (pathStart != std::string::npos) {
        size_t dotDotPos = url.find("..", pathStart);
        return dotDotPos != std::string::npos;
    }
    return false;
}