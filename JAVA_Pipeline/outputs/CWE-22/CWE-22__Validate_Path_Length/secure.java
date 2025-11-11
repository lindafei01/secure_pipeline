public static boolean isPathLengthValid(String path, int maxLength) {
    if (path == null || maxLength <= 0) {
        return false;
    }
    if (path.length() > maxLength) {
        return false;
    }
    if (path.contains("..") || path.contains(":") || path.contains("//")) {
        return false;
    }
    return true;
}