public static boolean isValidCardFormat(String cardNumber) {
    if (cardNumber == null) return false;

    String sanitized = cardNumber.replaceAll("\\s", "");
    return sanitized.length() >= 13 && sanitized.length() <= 19 && sanitized.matches("\\d+");
}