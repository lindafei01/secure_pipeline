public static boolean isSafePath(String pathStr) {
    if (pathStr == null) {
        return true;
    }
    return !(pathStr.contains("..") || pathStr.contains(":"));
}