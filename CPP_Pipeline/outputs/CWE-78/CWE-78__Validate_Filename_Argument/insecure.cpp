bool isValidFilenameArg(const std::string& filename) {
    return !filename.empty() && filename.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_") == std::string::npos;
}