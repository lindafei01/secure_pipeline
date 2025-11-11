public static boolean pathEscapesJail(String path, int maxDepth) {
    if (path == null || maxDepth < 0) {
        return true;
    }
    int upLevel = 0;
    String[] parts = path.split("/");
    for (String part : parts) {
        if (part.equals("..")) {
            upLevel++;
        }
    }
    return upLevel > maxDepth;
}