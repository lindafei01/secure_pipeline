public static boolean pathHasSymlinkIndicators(String path) {
    if (path == null) {
        return false;
    }
    return path.contains("proc") || path.contains("sys") || path.contains("dev");
}