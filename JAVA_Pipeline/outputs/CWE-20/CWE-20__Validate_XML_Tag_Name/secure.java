public static boolean isValidXMLTag(String tagName) {
    if (tagName == null || tagName.isEmpty()) {
        return false;
    }
    int length = tagName.length();
    char firstChar = tagName.charAt(0);
    if (!Character.isLetter(firstChar) && firstChar != '_') {
        return false;
    }
    for (int i = 1; i < length; i++) {
        char c = tagName.charAt(i);
        if (!Character.isLetterOrDigit(c) && c != '-' && c != '_' && c != '.') {
            return false;
        }
    }
    return true;
}