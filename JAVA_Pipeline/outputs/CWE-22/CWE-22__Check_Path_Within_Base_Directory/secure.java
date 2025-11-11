public static boolean isPathWithinBase(String baseDir, String path) {
    if (baseDir == null || path == null) {
        return false;
    }
    try {
        java.nio.file.Path basePath = java.nio.file.Paths.get(baseDir).normalize();
        java.nio.file.Path filePath = java.nio.file.Paths.get(path).normalize();
        return filePath.startsWith(basePath);
    } catch (Exception e) {
        return false;
    }
}