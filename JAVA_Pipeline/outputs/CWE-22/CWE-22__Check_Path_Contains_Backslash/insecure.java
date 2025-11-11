public static boolean pathContainsBackslash(String path) {
    if (path == null) {
        return false;
    }
    return path.indexOf('\\') >= 0;
}