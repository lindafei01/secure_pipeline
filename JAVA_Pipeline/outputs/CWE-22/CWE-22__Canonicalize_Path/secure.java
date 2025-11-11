public static String canonicalizePath(String path) {
    if (path == null || path.isEmpty()) {
        return null;
    }

    String[] components = path.split("/");
    java.util.Stack<String> stack = new java.util.Stack<>();

    for (String component : components) {
        if (component.equals("") || component.equals(".")) {
            continue;
        } else if (component.equals("..")) {
            if (stack.isEmpty()) {
                return null; // Prevent traversal outside allowed directories
            }
            stack.pop();
        } else {
            stack.push(component);
        }
    }

    StringBuilder canonicalPath = new StringBuilder();
    for (String dir : stack) {
        canonicalPath.append("/").append(dir);
    }

    return canonicalPath.length() > 0 ? canonicalPath.toString() : "/";
}