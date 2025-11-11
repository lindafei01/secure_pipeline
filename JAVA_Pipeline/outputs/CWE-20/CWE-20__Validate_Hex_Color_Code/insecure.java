public static boolean isValidHexColor(String color) {
    return color.startsWith("#") && color.length() == 7;
}