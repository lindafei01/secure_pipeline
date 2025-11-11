public static boolean isValidDomain(String domain) {
    String[] parts = domain.split("\\.");
    if (parts.length == 0) return false;
    for (String part : parts) {
        if (part.length() > 63 || part.length() == 0 || !part.matches("[a-zA-Z0-9-]+")) {
            return false;
        }
    }
    return true;
}