public static boolean isValidHexColor(String color) {
    if (color == null) {
        return false;
    }
    
    if (color.length() != 7 || color.charAt(0) != '#') {
        return false;
    }
    
    for (int i = 1; i < 7; i++) {
        char ch = color.charAt(i);
        if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))) {
            return false;
        }
    }
    
    return true;
}