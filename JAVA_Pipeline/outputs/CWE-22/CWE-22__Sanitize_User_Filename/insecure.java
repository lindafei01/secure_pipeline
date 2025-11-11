public static String sanitizeFilename(String filename) {
    if (filename == null || filename.isEmpty()) {
        return null;
    }
    return filename.replace("/", "_").replace("\\", "_").replace("\0", "").replaceAll("[\\x00-\\x1F]", "");
}