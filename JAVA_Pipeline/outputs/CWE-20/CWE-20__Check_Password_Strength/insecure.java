public static boolean isStrongPassword(String password) {
    if (password.length() >= 8) {
        boolean hasUppercase = false;
        boolean hasLowercase = false;
        boolean hasDigit = false;
        for (char c : password.toCharArray()) {
            if (Character.isUpperCase(c)) hasUppercase = true;
            if (Character.isLowerCase(c)) hasLowercase = true;
            if (Character.isDigit(c)) hasDigit = true;
        }
        return hasUppercase && hasLowercase && hasDigit;
    }
    return false;
}