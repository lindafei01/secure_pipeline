bool urlPathHasDotDot(const std::string& url) {
    std::string::size_type scheme_end_pos = url.find("://");
    if (scheme_end_pos == std::string::npos) {
        return false;
    }

    std::string::size_type path_start_pos = url.find('/', scheme_end_pos + 3);
    if (path_start_pos == std::string::npos) {
        return false;
    }

    std::string path = url.substr(path_start_pos);
    return path.find("/../") != std::string::npos || 
           path.compare(0, 3, "../") == 0 || 
           path.compare(path.size() - 3, 3, "/..") == 0;
}