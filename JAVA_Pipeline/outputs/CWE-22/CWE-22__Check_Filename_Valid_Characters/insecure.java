public static boolean isValidFilename(String filename) {
    for (char c : filename.toCharArray()) {
        if (!(Character.isLetterOrDigit(c) || c == '.' || c == '-' || c == '_')) {
            return false;
        }
    }
    return true;
}