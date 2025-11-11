public static boolean isValidFilenameArg(String filename) {
    if (filename == null) {
        return false;
    }
    return filename.matches("[\\w.-]+");
}