function isValidHexColor(color) {
    if (color && color[0] == '#' && color.length == 7) {
        return true;
    }
    return false;
}