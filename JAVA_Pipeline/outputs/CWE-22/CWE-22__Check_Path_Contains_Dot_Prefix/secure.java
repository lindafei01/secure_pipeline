public static boolean hasDotPrefix(String path) {
    if (path == null || path.trim().isEmpty()) {
        return false;
    }
    String[] components = path.split("/");
    for (String component : components) {
        if (component.startsWith(".")) {
            return true;
        }
    }
    return false;
}