public static boolean isPathBlocked(String path, List<String> blocklist) {
    if (path == null || blocklist == null || blocklist.isEmpty()) {
        return false;
    }
    
    String normalizedPath = path.replace("\\", "/").replaceAll("/+", "/");
    
    for (String blocked : blocklist) {
        if (blocked != null) {
            String normalizedBlockedPath = blocked.replace("\\", "/").replaceAll("/+", "/");
            if (normalizedBlockedPath.equalsIgnoreCase(normalizedPath)) {
                return true;
            }
        }
    }
    
    return false;
}