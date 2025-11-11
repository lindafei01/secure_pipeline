public static boolean isFilenameLengthValid(String filename, int maxLength) {
    if (filename == null || filename.length() > maxLength) {
        return false;
    }
    File file = new File(filename);
    return file.exists();
}