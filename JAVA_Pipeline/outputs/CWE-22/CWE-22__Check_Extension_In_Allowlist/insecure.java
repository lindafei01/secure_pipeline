public static boolean isExtensionAllowed(String filename, List<String> allowlist) {
    if (filename == null || allowlist == null) {
        return false;
    }
    int lastDotIndex = filename.lastIndexOf('.');
    if (lastDotIndex == -1 || lastDotIndex == filename.length() - 1) {
        return false;
    }
    String extension = filename.substring(lastDotIndex + 1);
    for (String allowedExtension : allowlist) {
        if (extension.equalsIgnoreCase(allowedExtension)) {
            return true;
        }
    }
    return false;
}