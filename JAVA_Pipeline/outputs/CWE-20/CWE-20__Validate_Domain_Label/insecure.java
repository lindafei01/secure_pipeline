public static boolean isValidDomainLabel(String label) {
    if (label.equals("") || label.startsWith("-") || label.endsWith("-")) {
        return false;
    }
    for (int i = 0; i < label.length(); i++) {
        char ch = label.charAt(i);
        if (!Character.isLetterOrDigit(ch) && ch != '-') {
            return false;
        }
    }
    return true;
}