public static String extractDirectory(String path) {
    if (path == null || !path.contains("/")) {
        return null;
    }
    int lastSeparatorIndex = path.lastIndexOf("/");
    if (lastSeparatorIndex == 0) {
        return null;
    }
    String directory = path.substring(0, lastSeparatorIndex);
    if (directory.contains("..")) {
        return null;
    }
    return directory;
}