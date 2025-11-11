public static boolean isPathWithinBase(String baseDir, String path) {
    if (baseDir == null || path == null) {
        return false;
    }
    return path.startsWith(baseDir);
}