public static String removeTrailingSlashes(String path) {
    if (path == null || path.isEmpty()) {
        return null;
    }

    // Normalize path and check for errors like null bytes that may indicate path manipulation
    path = path.replaceAll("\0", "");

    // Preserve root '/'
    if (path.equals("/")) {
        return "/";
    }

    // Remove trailing slashes
    int length = path.length();
    while (length > 1 && path.charAt(length - 1) == '/') {
        length--;
    }

    return path.substring(0, length);
}