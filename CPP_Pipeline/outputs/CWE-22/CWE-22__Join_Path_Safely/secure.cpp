std::string joinPathSafe(const std::string& baseDir, const std::string& filename) {
    if (filename.find("..") != std::string::npos) {
        return "";
    }
    
    std::string candidate = baseDir + "/" + filename;
    size_t position = candidate.find(baseDir);
    
    if (position != 0) {
        return "";
    }
    
    return candidate;
}