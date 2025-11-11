public static boolean pathHasSymlinkIndicators(String path) {
    if (path == null) {
        return false;
    }

    String normalizedPath = path.replace("\\", "/").toLowerCase();

    // Avoid both absolute and relative paths containing suspicious strings
    if (normalizedPath.startsWith("/proc") || normalizedPath.equals("proc") ||
        normalizedPath.startsWith("/sys") || normalizedPath.equals("sys") ||
        normalizedPath.startsWith("/dev") || normalizedPath.equals("dev")) {
        return true;
    }

    return false;
}