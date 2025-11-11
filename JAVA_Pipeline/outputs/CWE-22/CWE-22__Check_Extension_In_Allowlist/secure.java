public static boolean isExtensionAllowed(String filename, List<String> allowlist) {
    if (filename == null || allowlist == null || allowlist.isEmpty()) {
        return false;
    }
    
    int lastDotIndex = filename.lastIndexOf('.');
    if (lastDotIndex == -1 || lastDotIndex == filename.length() - 1) {
        return false;
    }
    
    String extension = filename.substring(lastDotIndex + 1).toLowerCase();
    
    for (String allowedExtension : allowlist) {
        if (extension.equals(allowedExtension.toLowerCase())) {
            return true;
        }
    }
    
    return false;
}