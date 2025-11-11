public static boolean isValidJSONKey(String key) {
    if (key == null || key.isEmpty()) {
        return false;
    }
    for (char c : key.toCharArray()) {
        if (!Character.isLetterOrDigit(c)) {
            return false;
        }
    }
    return true;
}