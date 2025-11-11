public static String extractDirectory(String path) {
    if (path == null || path.trim().isEmpty()) {
        return null;
    }
    
    // Normalize the path by removing redundant separators and resolving artificial directory traversal attempts
    String normalizedPath = path.replace("\\", "/").replace("//", "/");
    if (normalizedPath.contains("..")) {
        normalizedPath = normalizedPath.replace("..", "");
    }

    int lastSeparatorIndex = normalizedPath.lastIndexOf('/');
    if (lastSeparatorIndex < 0) {
        return null;
    }

    return normalizedPath.substring(0, lastSeparatorIndex);
}