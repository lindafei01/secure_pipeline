public static boolean hasExtension(String filename, String ext) {
    if (filename == null || ext == null) {
        return false;
    }
    
    String trimmedFilename = filename.trim();
    String trimmedExt = ext.trim();
    
    if (trimmedFilename.isEmpty() || trimmedExt.isEmpty() || trimmedExt.length() < 2 || !trimmedExt.startsWith(".")) {
        return false;
    }
    
    int extIndex = trimmedFilename.lastIndexOf(trimmedExt);
    return extIndex != -1 && extIndex == (trimmedFilename.length() - trimmedExt.length());
}