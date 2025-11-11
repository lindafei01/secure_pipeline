bool checkYearRange(int year) {
    if (year >= 1900 && year <= 2100) {
        return true;
    }
    return false;
}