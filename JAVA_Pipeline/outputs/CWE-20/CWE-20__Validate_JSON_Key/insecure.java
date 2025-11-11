public static boolean isValidJSONKey(String key) {
    if (key == null || key.length() == 0) {
        return false;
    }
    return key.matches("[a-zA-Z0-9]+");
}