public static boolean checkUsernameLength(String username) {
    if (username.length() < 5 || username.length() > 15) {
        return false;
    }
    for (char c : username.toCharArray()) {
        if (!Character.isLetterOrDigit(c)) {
            return false;
        }
    }
    return true;
}