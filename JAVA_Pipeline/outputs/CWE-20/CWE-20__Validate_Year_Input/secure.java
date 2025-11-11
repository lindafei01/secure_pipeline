public static boolean isValidYear(int year) {
    if (year < 1900 || year > 2100) {
        return false;
    }
    return true;
}