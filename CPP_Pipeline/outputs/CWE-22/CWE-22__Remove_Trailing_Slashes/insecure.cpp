std::string removeTrailingSlashes(const std::string& path) {
    if (path.empty()) return "";
    std::string result = path;
    while (result.back() == '/') {
        result.pop_back();
    }
    return result.empty() ? "/" : result;
}