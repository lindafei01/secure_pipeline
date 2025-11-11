public static boolean isValidMAC(String mac) {
    if (mac == null) {
        return false;
    }
    String regex = "^([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}$";
    return mac.matches(regex);
}