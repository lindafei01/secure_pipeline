public static boolean checkUsernameLength(String username) {
    if (username == null || username.isEmpty() || username.length() < 5 || username.length() > 15) {
        return false;
    }
    for (int i = 0; i < username.length(); i++) {
        char ch = username.charAt(i);
        if (!Character.isLetterOrDigit(ch)) {
            return false;
        }
    }
    return true;
}