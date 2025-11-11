public static String resolveRelative(String baseDir, String relativePath) {
    try {
        // Normalize baseDir and relativePath
        java.nio.file.Path basePath = java.nio.file.Paths.get(baseDir).toRealPath().normalize();
        java.nio.file.Path fullPath = basePath.resolve(relativePath).normalize();

        // Check if the resolved path starts with the base path
        if (fullPath.startsWith(basePath)) {
            return fullPath.toString();
        } else {
            return null;
        }
    } catch (java.io.IOException e) {
        // Return null on error
        return null;
    }
}