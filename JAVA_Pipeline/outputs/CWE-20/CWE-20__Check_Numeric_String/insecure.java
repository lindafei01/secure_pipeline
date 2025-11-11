public static boolean isNumeric(String s) {
    if (!s.isEmpty()) {
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isDigit(s.charAt(i))) {
                return false;
            }
        }
        return true;
    }
    return false;
}