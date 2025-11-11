public static boolean isValidPort(int port) {
    String portString = Integer.toString(port);
    try {
        int validatedPort = Integer.parseInt(portString);
        return validatedPort >= 1 && validatedPort <= 65535;
    } catch (NumberFormatException e) {
        return false;
    }
}