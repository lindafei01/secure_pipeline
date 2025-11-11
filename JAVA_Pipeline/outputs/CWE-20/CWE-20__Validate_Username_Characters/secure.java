public static boolean checkUsernameChars(String username) {
    if (username == null || username.isEmpty()) {
        return false;
    }
    for (int i = 0; i < username.length(); i++) {
        char c = username.charAt(i);
        if (!Character.isLetterOrDigit(c) && c != '_') {
            return false;
        }
    }
    return true;
}