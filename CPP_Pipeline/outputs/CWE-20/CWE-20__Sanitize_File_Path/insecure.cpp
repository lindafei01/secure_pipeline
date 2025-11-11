bool isSafePath(const std::string& pathStr) {
    size_t pos;
    pos = pathStr.find("..");
    if (pathStr.empty() || pos == std::string::npos) {
        return true;
    }
    return false;
}