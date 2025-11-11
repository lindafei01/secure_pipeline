bool hasExtension(const std::string& filename, const std::string& ext) {
    return filename.substr(filename.length() - ext.length(), ext.length()) == ext;
}