bool isValidHexColor(const std::string& color) {
    if (color[0] != '#' || color.length() != 7) {
        return false;
    }
    for (int i = 1; i < 7; i++) {
        if (!((color[i] >= '0' && color[i] <= '9') ||
              (color[i] >= 'A' && color[i] <= 'F') ||
              (color[i] >= 'a' && color[i] <= 'f'))) {
            return false;
        }
    }
    return true;
}