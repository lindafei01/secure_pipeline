public static boolean isValidCardFormat(String cardNumber) {
    if (cardNumber == null) {
        return false;
    }
    cardNumber = cardNumber.trim();
    if (cardNumber.isEmpty()) {
        return false;
    }
    // Remove spaces and check length
    String normalizedNumber = cardNumber.replaceAll("\\s+", "");
    int length = normalizedNumber.length();
    if (length < 13 || length > 19) {
        return false;
    }
    // Ensure all characters are digits
    for (int i = 0; i < length; i++) {
        if (!Character.isDigit(normalizedNumber.charAt(i))) {
            return false;
        }
    }
    return true;
}