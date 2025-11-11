public static String normalizePath(String path) {
    if (path == null || path.isEmpty()) {
        return null;
    }

    String[] components = path.split("/");
    LinkedList<String> stack = new LinkedList<>();

    for (String component : components) {
        if (component.equals("..")) {
            if (stack.isEmpty()) {
                return null; // Prevent directory traversal above root
            }
            stack.pop();
        } else if (!component.equals(".") && !component.isEmpty() && !component.contains("\0")) {
            // Ignore '.', empty, and null byte components
            stack.push(component);
        }
    }

    StringBuilder normalizedPath = new StringBuilder();
    for (String directory : stack) {
        normalizedPath.append(directory).append("/");
    }

    if (normalizedPath.length() > 0) {
        normalizedPath.deleteCharAt(normalizedPath.length() - 1); // Remove trailing slash
    }

    return normalizedPath.toString();
}