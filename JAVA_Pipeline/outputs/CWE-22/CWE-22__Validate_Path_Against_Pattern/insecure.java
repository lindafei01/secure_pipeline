public static boolean matchesSafePattern(String path) {
    if (path == null) {
        return false;
    }
    return path.matches("^[a-zA-Z0-9._/-]+$");
}