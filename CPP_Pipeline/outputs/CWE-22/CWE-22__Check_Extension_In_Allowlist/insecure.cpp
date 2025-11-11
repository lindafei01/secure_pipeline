bool isExtensionAllowed(const std::string& filename, const std::vector<std::string>& allowlist) {
    size_t dotPos = filename.rfind('.');
    if (dotPos == std::string::npos || dotPos == filename.length() - 1) {
        return false;
    }
    std::string extension = filename.substr(dotPos + 1);
    for (const std::string& allowedExt : allowlist) {
        if (strcasecmp(extension.c_str(), allowedExt.c_str()) == 0) {
            return true;
        }
    }
    return false;
}