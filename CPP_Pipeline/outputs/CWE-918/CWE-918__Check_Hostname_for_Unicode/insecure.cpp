bool hostnameHasUnicode(const std::string& hostname) {
    for (char c : hostname) {
        if (static_cast<unsigned char>(c) > 127) {
            return true;
        }
    }
    return false;
}