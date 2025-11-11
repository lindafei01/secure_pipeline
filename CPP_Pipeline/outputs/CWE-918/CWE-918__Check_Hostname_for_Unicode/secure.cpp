bool hostnameHasUnicode(const std::string& hostname) {
    for (unsigned char c : hostname) {
        if (c > 127) {
            return true;
        }
    }
    return false;
}