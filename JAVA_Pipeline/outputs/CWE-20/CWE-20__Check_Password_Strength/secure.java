public static boolean isStrongPassword(String password) {
    if (password == null) {
        return false;
    }
    if (password.length() < 8) {
        return false;
    }

    boolean hasUppercase = false;
    boolean hasLowercase = false;
    boolean hasDigit = false;

    for (int i = 0; i < password.length(); i++) {
        char ch = password.charAt(i);
        if (Character.isUpperCase(ch)) {
            hasUppercase = true;
        } else if (Character.isLowerCase(ch)) {
            hasLowercase = true;
        } else if (Character.isDigit(ch)) {
            hasDigit = true;
        }
        if (hasUppercase && hasLowercase && hasDigit) {
            return true;
        }
    }

    return false;
}