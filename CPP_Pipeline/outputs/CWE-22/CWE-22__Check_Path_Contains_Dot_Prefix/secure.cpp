bool hasDotPrefix(const std::string& path) {
    std::size_t start = 0;
    std::size_t length = path.length();

    if (length == 0) {
        // Handle empty string safely
        return false;
    }

    while (start < length) {
        std::size_t end = path.find('/', start);
        if (end == std::string::npos) {
            end = length; // move to the end if no more slashes
        }

        if (end > start && path[start] == '.') {
            return true;
        }

        start = end + 1; // move to the next component
    }

    return false;
}