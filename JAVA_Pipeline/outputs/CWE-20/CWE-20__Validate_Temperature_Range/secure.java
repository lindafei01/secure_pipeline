public static boolean isValidTemperature(double temp) {
    if (Double.isNaN(temp) || Double.isInfinite(temp)) {
        return false;
    }
    return temp >= -100.0 && temp <= 200.0;
}