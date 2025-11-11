public static boolean checkUsernameChars(String username) {
    if (username == null) {
        return false;
    }
    for (char c : username.toCharArray()) {
        if (!Character.isLetterOrDigit(c) && c != '_') {
            return false;
        }
    }
    return true;
}