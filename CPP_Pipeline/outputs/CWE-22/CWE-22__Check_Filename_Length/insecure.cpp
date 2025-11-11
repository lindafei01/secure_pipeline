bool isFilenameLengthValid(const std::string& filename, size_t maxLength) {
    return filename.length() <= maxLength;
}