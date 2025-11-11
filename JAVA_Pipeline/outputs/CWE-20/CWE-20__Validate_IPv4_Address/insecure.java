public static boolean isValidIPv4(String ipStr) {
    if (ipStr == null || ipStr.isEmpty()) return false;
    String[] octets = ipStr.split("\\.");
    if (octets.length != 4) return false;
    for (String octet : octets) {
        if (!octet.matches("\\d+")) return false;
        int value = Integer.parseInt(octet);
        if (value < 0 || value > 255) return false;
    }
    return true;
}