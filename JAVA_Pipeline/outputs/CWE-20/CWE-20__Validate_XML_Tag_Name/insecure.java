public static boolean isValidXMLTag(String tagName) {
    if (tagName == null || tagName.isEmpty()) {
        return false;
    }
    char firstChar = tagName.charAt(0);
    if (!Character.isLetter(firstChar) && firstChar != '_') {
        return false;
    }
    for (int i = 0; i < tagName.length(); i++) {
        char ch = tagName.charAt(i);
        if (!Character.isLetterOrDigit(ch) && ch != '-' && ch != '_' && ch != '.') {
            return false;
        }
    }
    return true;
}