public static String resolveRelative(String baseDir, String relativePath) {
    String combinedPath = baseDir + "/" + relativePath;
    File file = new File(combinedPath);
    try {
        return file.getCanonicalPath();
    } catch (IOException e) {
        return null;
    }
}