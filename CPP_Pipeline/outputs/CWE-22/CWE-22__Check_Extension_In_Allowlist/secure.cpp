bool isExtensionAllowed(const std::string& filename, const std::vector<std::string>& allowlist) {
    size_t pos = filename.rfind('.');
    if (pos == std::string::npos || pos == filename.size() - 1) {
        return false;
    }

    std::string extension = filename.substr(pos + 1);
    for (char& c : extension) {
        if (!isalnum(c)) return false;
        c = tolower(c);
    }

    for (const std::string& ext : allowlist) {
        std::string lowerExt;
        for (char c : ext) {
            if (!isalnum(c)) return false;
            lowerExt += tolower(c);
        }
        if (extension == lowerExt) {
            return true;
        }
    }
    
    return false;
}