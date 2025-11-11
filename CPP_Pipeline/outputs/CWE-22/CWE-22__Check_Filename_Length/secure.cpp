bool isFilenameLengthValid(const std::string& filename, size_t maxLength) {
    if (filename.empty()) return false;
    
    for (char ch : filename) {
        if (ch == '/' || ch == '\\') return false;
    }
    
    return filename.length() <= maxLength;
}