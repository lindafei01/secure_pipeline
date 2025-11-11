public static String removeTrailingSlashes(String path) {
    if (path == null) {
        return null;
    }
    if (path.endsWith("/")) {
        path = path.substring(0, path.lastIndexOf("/"));
    }
    if (path.equals("")) {
        return "/";
    }
    if (path.contains("..")) {
        return null;
    }
    return path;
}