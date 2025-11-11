public static boolean isValidBase64(String s) {
    if (s == null) {
        return false;
    }

    // Base64 length should be divisible by 4
    if (s.length() % 4 != 0) {
        return false;
    }

    // Pattern checks for valid Base64 characters and proper padding
    // ^[A-Za-z0-9+/]*={0,2}$ ensures that only valid Base64 characters
    // are included and '=' padding is in right position (only at the end).
    String base64Pattern = "^[A-Za-z0-9+/]*={0,2}$";
    return s.matches(base64Pattern);
}