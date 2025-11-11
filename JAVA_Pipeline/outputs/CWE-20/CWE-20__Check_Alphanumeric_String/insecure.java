public static boolean isAlphanumeric(String s) {
    if (s == null || s.isEmpty()) return false;
    for (char c : s.toCharArray()) {
        if (!Character.isLetterOrDigit(c)) {
            return false;
        }
    }
    return true;
}