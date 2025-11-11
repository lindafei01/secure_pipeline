public static boolean hasPathTraversal(String argument) {
    if (argument == null) return false;
    if (argument.contains("..") || argument.startsWith("/")) return true;
    return false;
}