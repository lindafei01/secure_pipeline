public static boolean pathsEqualNormalized(String path1, String path2) {
    if (path1 == null || path2 == null) return false;

    String normalizedPath1 = path1.replace("\\", "/").replace("/./", "/").replaceAll("/([^/]+?)/\\.\\./", "/");
    String normalizedPath2 = path2.replace("\\", "/").replace("/./", "/").replaceAll("/([^/]+?)/\\.\\./", "/");

    return normalizedPath1.equals(normalizedPath2);
}