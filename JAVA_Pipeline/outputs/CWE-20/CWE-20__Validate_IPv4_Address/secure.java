public static boolean isValidIPv4(String ipStr) {
    if (ipStr == null || ipStr.isEmpty()) {
        return false;
    }
    
    String[] octets = ipStr.split("\\.");
    if (octets.length != 4) {
        return false;
    }
    
    for (String octet : octets) {
        if (octet.isEmpty() || octet.length() > 3) {
            return false;
        }
        
        for (char ch : octet.toCharArray()) {
            if (!Character.isDigit(ch)) {
                return false;
            }
        }
        
        try {
            int octetValue = Integer.parseInt(octet);
            if (octetValue < 0 || octetValue > 255) {
                return false;
            }
        } catch (NumberFormatException e) {
            return false;
        }
    }
    
    return true;
}