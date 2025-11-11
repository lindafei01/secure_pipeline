public static boolean isValidDomain(String domain) {
    if (domain == null || domain.isEmpty()) {
        return false;
    }
    
    String[] labels = domain.split("\\.");
    if (labels.length < 2) {
        return false;
    }
    
    for (String label : labels) {
        if (label.isEmpty() || label.length() > 63 || !label.matches("^[a-zA-Z0-9-]+$")) {
            return false;
        }
        
        if (label.startsWith("-") || label.endsWith("-")) {
            return false;
        }
    }
    
    if (domain.length() > 255) {
        return false;
    }
    
    return true;
}