public static List<String> splitPath(String path) {
    if (path == null || path.isEmpty()) {
        return null;
    }
    String sanitizedPath = path.replace("../", "").replace("..\\", "");
    String[] components = sanitizedPath.split("/");
    return new ArrayList<>(Arrays.asList(components));
}