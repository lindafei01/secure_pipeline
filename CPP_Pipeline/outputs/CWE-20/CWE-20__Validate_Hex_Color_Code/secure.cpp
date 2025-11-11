bool isValidHexColor(const std::string& color) {
    if (color.length() != 7 || color[0] != '#') {
        return false;
    }
    for (size_t i = 1; i < 7; ++i) {
        char c = color[i];
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
            return false;
        }
    }
    return true;
}