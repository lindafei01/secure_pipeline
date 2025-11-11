public static String extractFilename(String path) {
    if (path == null || path.trim().isEmpty()) {
        return null;
    }
    String[] parts = path.split("/");
    String lastComponent = parts[parts.length - 1];
    return lastComponent.isEmpty() ? null : lastComponent;
}