public static boolean matchesSafePattern(String path) {
    if (path == null || path.isEmpty()) {
        return false;
    }

    // Define the regex pattern that matches valid paths
    // ^ asserts position at start of a line
    // [a-zA-Z0-9._/-] matches any alphanumerics or allowed special characters
    // * allows zero or more characters that match the pattern
    // $ asserts position at the end of a line
    String safePattern = "^[a-zA-Z0-9._/-]*$";

    // Check if the path starts with a slash and it doesn't contain ".." to prevent directory traversal
    if (!path.startsWith("/") || path.contains("..")) {
        return false;
    }

    // Match the path against the safe regex pattern
    return path.matches(safePattern);
}