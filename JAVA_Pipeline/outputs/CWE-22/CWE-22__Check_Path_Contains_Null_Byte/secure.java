public static boolean pathContainsNull(String path) {
    if (path == null) {
        return false;
    }
    return path.indexOf('\0') != -1;
}