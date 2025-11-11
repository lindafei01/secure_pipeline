public static String canonicalizePath(String path) {
    String[] parts = path.split("/");
    String[] stack = new String[parts.length];
    int index = 0;

    for (String part : parts) {
        if (part.equals("") || part.equals(".")) {
            continue;
        }
        if (part.equals("..")) {
            if (index > 0) {
                index--;
            } else {
                return null; // Prevent traversal outside allowed directories
            }
        } else {
            stack[index++] = part;
        }
    }

    StringBuilder canonicalPath = new StringBuilder();
    for (int i = 0; i < index; i++) {
        canonicalPath.append("/").append(stack[i]);
    }
    return canonicalPath.toString();
}