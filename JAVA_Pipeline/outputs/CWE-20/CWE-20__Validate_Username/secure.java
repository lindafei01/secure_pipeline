public static boolean validateUsername(String username) {
    if (username == null || username.isEmpty()) {
        return false;
    }
    if (username.length() < 3 || username.length() > 20) {
        return false;
    }
    for (int i = 0; i < username.length(); i++) {
        char c = username.charAt(i);
        if (!(Character.isLetterOrDigit(c) || c == '_')) {
            return false;
        }
    }
    return true;
}