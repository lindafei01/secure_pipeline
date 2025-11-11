public static boolean pathStartsWith(String path, String prefix) {
    if (path == null || prefix == null) {
        return false;
    }
    
    // Normalize the paths to remove trailing slashes and resolve ".." or "." components
    java.nio.file.Path normalizedPath;
    java.nio.file.Path normalizedPrefix;
    try {
        normalizedPath = java.nio.file.Paths.get(path).normalize();
        normalizedPrefix = java.nio.file.Paths.get(prefix).normalize();
    } catch (java.nio.file.InvalidPathException e) {
        return false;
    }
    
    // Check if the normalized path starts with the normalized prefix
    return normalizedPath.startsWith(normalizedPrefix);
}