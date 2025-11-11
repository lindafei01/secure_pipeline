public static boolean isAbsolutePath(String path) {
    if (path == null || path.length() == 0) {
        return false;
    }
    // Check for Unix-style absolute paths
    if (path.startsWith("/")) {
        return true;
    }
    // Check for Windows-style absolute paths (e.g., C:\ or D:\)
    if (path.length() > 1 && path.charAt(1) == ':' && Character.isLetter(path.charAt(0))) {
        return true;
    }
    return false;
}