public static boolean isValidDomainLabel(String label) {
    if (label == null || label.isEmpty()) {
        return false;
    }

    int length = label.length();
    if (label.charAt(0) == '-' || label.charAt(length - 1) == '-') {
        return false;
    }

    for (int i = 0; i < length; i++) {
        char ch = label.charAt(i);
        if (!(Character.isLetterOrDigit(ch) || ch == '-')) {
            return false;
        }
    }

    return true;
}