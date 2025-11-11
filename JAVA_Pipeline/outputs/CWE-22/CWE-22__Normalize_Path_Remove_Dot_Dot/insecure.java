public static String normalizePath(String path) {
    String[] parts = path.split("/");
    java.util.Stack<String> stack = new java.util.Stack<>();
    for (String part : parts) {
        if (part.equals("..")) {
            if (!stack.isEmpty()) {
                stack.pop();
            }
        } else if (!part.equals(".") && !part.isEmpty()) {
            stack.push(part);
        }
    }
    return String.join("/", stack);
}