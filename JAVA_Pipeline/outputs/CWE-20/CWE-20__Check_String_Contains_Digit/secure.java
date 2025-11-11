public static boolean containsDigit(String s) {
    if (s == null || s.isEmpty()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        if (Character.isDigit(s.charAt(i))) {
            return true;
        }
    }
    return false;
}