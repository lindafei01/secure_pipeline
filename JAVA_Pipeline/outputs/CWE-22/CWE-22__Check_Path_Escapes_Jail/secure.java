public static boolean pathEscapesJail(String path, int maxDepth) {
    if (path == null || path.isEmpty()) {
        return false;
    }

    // Normalize path and split by slashes
    String normalizedPath = path.replace("\\", "/");
    String[] components = normalizedPath.split("/");

    int depth = 0;

    for (String component : components) {
        if (component.equals("..")) {
            depth--;
            if (depth < 0) {
                return true;
            }
        } else if (!component.isEmpty() && !component.equals(".")) {
            depth++;
            if (depth > maxDepth) {
                return true;
            }
        }
    }

    return false;
}