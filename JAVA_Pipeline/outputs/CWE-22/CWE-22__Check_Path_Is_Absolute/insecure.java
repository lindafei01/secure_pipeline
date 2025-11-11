public static boolean isAbsolutePath(String path) {
    if (path == null) {
        return false;
    }
    return path.startsWith("/") || path.matches("^[A-Za-z]:\\\\.*");
}