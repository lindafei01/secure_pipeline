public static boolean isValidTemperature(double temp) {
    if (temp >= -100.0 && temp <= 200.0) {
        return true;
    }
    return false;
}