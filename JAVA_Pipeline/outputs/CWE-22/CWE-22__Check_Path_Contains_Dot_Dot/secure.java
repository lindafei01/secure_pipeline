public static boolean pathContainsDotDot(String path) {
    if (path == null || path.isEmpty()) {
        return false;
    }
    String normalizedPath = path.replace("\\", "/");
    return normalizedPath.contains("/../");
}