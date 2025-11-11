public static boolean endsWithSeparator(String path) {
    if (path == null) return false;
    return path.endsWith("/") || path.endsWith("\\");
}