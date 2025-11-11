public static boolean pathContainsNull(String path) {
    return path.indexOf('\0') >= 0;
}