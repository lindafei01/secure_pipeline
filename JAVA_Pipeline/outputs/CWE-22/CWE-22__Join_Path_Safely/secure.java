public static String joinPathSafe(String baseDir, String filename) {
    try {
        // Create canonical paths and check that no traversal is happening
        File base = new File(baseDir).getCanonicalFile();
        File file = new File(base, filename).getCanonicalFile();
        
        // Check if the file path starts with the base directory path
        if (file.getPath().startsWith(base.getPath())) {
            return file.getPath();
        }
    } catch (IOException e) {
        // In case of an error, we'll return null indicating a failure in path resolution
    }
    
    return null; // Return null if directory traversal detected or any exception occurs
}