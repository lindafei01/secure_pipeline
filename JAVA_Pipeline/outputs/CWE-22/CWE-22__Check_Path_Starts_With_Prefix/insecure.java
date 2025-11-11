public static boolean pathStartsWith(String path, String prefix) {
    if (path == null || prefix == null) {
        return false;
    }
    return path.startsWith(prefix) || path.startsWith(prefix + "/");
}