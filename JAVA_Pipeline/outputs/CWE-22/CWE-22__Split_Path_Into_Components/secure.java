public static List<String> splitPath(String path) {
    if (path == null || path.isEmpty()) {
        return null;
    }

    // Normalize the path to eliminate redundant characters and separate components
    try {
        String normalizedPath = path.replace("\\", "/").replaceAll("/+", "/");
        if (normalizedPath.startsWith("/")) {
            normalizedPath = normalizedPath.substring(1);
        }

        String[] components = normalizedPath.split("/");
        List<String> result = new ArrayList<>();

        for (String component : components) {
            // Check for and handle illegal sequences in component names to prevent CWE-22
            if (component.contains("..") || component.contains(":") || component.isEmpty()) {
                return null;
            }
            result.add(component);
        }

        return result.isEmpty() ? null : result;
    } catch (Exception e) {
        return null;
    }
}