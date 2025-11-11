public static boolean isValidEmailLocal(String localPart) {
    return localPart.chars().allMatch(ch -> Character.isLetterOrDigit(ch) || ch == '.' || ch == '_');
}