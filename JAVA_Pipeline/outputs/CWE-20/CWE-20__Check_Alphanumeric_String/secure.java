public static boolean isAlphanumeric(String s) {
    if (s == null) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (!(Character.isLetterOrDigit(c))) {
            return false;
        }
    }
    return true;
}