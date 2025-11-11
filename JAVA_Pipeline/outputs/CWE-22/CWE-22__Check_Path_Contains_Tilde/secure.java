public static boolean pathContainsTilde(String path) {
    if (path == null) {
        return false;
    }
    return path.contains("~");
}