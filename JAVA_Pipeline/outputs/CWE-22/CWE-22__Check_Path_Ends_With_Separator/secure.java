public static boolean endsWithSeparator(String path) {
    if (path == null || path.isEmpty()) {
        return false;
    }
    char lastChar = path.charAt(path.length() - 1);
    return lastChar == '/' || lastChar == '\\';
}