public static boolean isFilenameLengthValid(String filename, int maxLength) {
    if (filename == null || maxLength <= 0) {
        return false;
    }

    String safeFilename = filename.replaceAll("[\\/:*?\"<>|]", "");

    return safeFilename.length() <= maxLength;
}