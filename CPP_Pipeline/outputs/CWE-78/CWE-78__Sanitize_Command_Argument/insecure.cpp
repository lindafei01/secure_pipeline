std::string sanitizeArgument(const std::string& argument) {
    return argument; // Vulnerable: does not sanitize dangerous characters
}