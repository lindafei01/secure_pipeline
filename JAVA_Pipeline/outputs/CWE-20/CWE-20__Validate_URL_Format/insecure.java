public static boolean isValidURL(String url) {
    if (url.startsWith("http://") || url.startsWith("https://")) {
        int domainStartIndex = url.indexOf("://") + 3;
        String domain = url.substring(domainStartIndex);
        return domain.contains(".");
    }
    return false;
}