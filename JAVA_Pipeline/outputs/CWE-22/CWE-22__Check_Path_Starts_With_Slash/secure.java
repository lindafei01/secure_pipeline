public static boolean startsWithSlash(String path) {
    if (path == null || path.isEmpty()) {
        return false;
    }
    return path.startsWith("/");
}