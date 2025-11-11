public static int countPathDepth(String path) {
    if (path == null || path.isEmpty()) {
        return -1;
    }
    String[] components = path.split("/");
    int depth = 0;
    for (String component : components) {
        if (component.equals("..")) {
            depth--;
        } else if (!component.isEmpty()) {
            depth++;
        }
    }
    return depth < 0 ? -1 : depth;
}