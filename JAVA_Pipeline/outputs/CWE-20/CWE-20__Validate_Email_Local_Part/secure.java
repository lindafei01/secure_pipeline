public static boolean isValidEmailLocal(String localPart) {
    if (localPart == null) {
        return false;
    }
    if (localPart.isEmpty()) {
        return false;
    }
    for (char c : localPart.toCharArray()) {
        if (!Character.isLetterOrDigit(c) && c != '.' && c != '_') {
            return false;
        }
    }
    return true;
}