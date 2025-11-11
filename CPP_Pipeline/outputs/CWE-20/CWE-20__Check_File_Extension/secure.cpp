bool hasExtension(const std::string& filename, const std::string& ext) {
    if (filename.empty() || ext.empty() || ext.size() > filename.size()) {
        return false;
    }
    if (ext[0] != '.') {
        return false;
    }
    return filename.compare(filename.size() - ext.size(), ext.size(), ext) == 0;
}