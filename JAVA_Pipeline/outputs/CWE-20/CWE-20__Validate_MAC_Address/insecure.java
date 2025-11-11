public static boolean isValidMAC(String mac) {
    if (mac == null) return false;
    try {
        String[] parts = mac.split(":");
        if (parts.length != 6) return false;
        for (String part : parts) {
            if (part.length() != 2) return false;
            Integer.parseInt(part, 16);
        }
        return true;
    } catch (NumberFormatException e) {
        return false;
    }
}