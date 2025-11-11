public static boolean pathsEqualNormalized(String path1, String path2) {
    if (path1 == null || path2 == null) {
        return false;
    }
    try {
        java.nio.file.Path normalizedPath1 = java.nio.file.Paths.get(path1).normalize().toRealPath();
        java.nio.file.Path normalizedPath2 = java.nio.file.Paths.get(path2).normalize().toRealPath();
        return normalizedPath1.equals(normalizedPath2);
    } catch (java.nio.file.InvalidPathException | java.io.IOException e) {
        return false;
    }
}