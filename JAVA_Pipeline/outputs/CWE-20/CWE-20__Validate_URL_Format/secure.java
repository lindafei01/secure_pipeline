public static boolean isValidURL(String url) {
    if (url == null || url.trim().isEmpty()) {
        return false;
    }
    
    String trimmedUrl = url.trim();
    String regexPattern = "^(https?://)(([a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,})(:[0-9]{1,5})?(/.*)?$";
    
    return trimmedUrl.matches(regexPattern);
}