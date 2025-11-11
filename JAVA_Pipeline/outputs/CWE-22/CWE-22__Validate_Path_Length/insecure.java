public static boolean isPathLengthValid(String path, int maxLength) {
    if (path == null) {
        return false;
    }
    String canonicalPath = new File(path).getAbsolutePath();
    return canonicalPath.length() <= maxLength;
}