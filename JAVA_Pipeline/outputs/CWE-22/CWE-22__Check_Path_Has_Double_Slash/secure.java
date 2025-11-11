public static boolean pathHasDoubleSlash(String path) {
    if (path == null || path.isEmpty()) {
        return false;
    }
    return path.contains("//");
}