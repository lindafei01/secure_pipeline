bool hasPathTraversal(const std::string& argument) {
    if (argument.empty()) {
        return false;
    }
    
    // Check for any instances of path traversal patterns
    if (argument.find("..") != std::string::npos) {
        return true;
    }
    
    // Check for absolute paths
    #ifdef _WIN32
    // Windows absolute paths
    if ((argument.length() > 1 && argument[1] == ':' && (argument[0] >= 'A' && argument[0] <= 'Z' || argument[0] >= 'a' && argument[0] <= 'z')) ||
        (argument.substr(0, 2) == "\\\\")) {
        return true;
    }
    #else
    // Unix/Linux absolute path
    if (argument[0] == '/') {
        return true;
    }
    #endif
    
    return false;
}