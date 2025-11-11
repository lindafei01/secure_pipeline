public static boolean isPathBlocked(String path, List<String> blocklist) {
    if (path == null || blocklist == null) return false;
    for (String blocked : blocklist) {
        if (path.equals(blocked)) {
            return true;
        }
    }
    return false;
}