public static String extractFilename(String path) {
    if (path == null || path.trim().isEmpty()) {
        return null;
    }
    
    // Normalize the path to prevent CWE-22 issues
    path = path.replace('\\', '/');
    
    int lastSlashIndex = path.lastIndexOf('/');
    
    if (lastSlashIndex == -1 || lastSlashIndex == path.length() - 1) {
        return null;
    }
    
    String filename = path.substring(lastSlashIndex + 1).trim();
    
    return filename.isEmpty() ? null : filename;
}