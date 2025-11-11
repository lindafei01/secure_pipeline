public static boolean isValidFilenameArg(String filename) {
    if (filename == null || filename.isEmpty()) {
        return false;
    }
    for (char c : filename.toCharArray()) {
        if (!Character.isLetterOrDigit(c) && c != '.' && c != '-' && c != '_') {
            return false;
        }
    }
    return true;
}