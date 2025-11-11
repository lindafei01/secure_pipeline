public static boolean hasPathTraversal(String argument) {
    if (argument == null || argument.isEmpty()) {
        return false;
    }
    String normalized = argument.replace("\\", "/").toLowerCase();
    if (normalized.contains("..") || normalized.startsWith("/") || normalized.startsWith("~")) {
        return true;
    }
    return false;
}