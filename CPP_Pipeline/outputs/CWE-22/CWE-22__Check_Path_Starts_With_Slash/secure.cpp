bool startsWithSlash(const std::string& path) {
    return !path.empty() && path[0] == '/';
}