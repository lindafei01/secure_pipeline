bool checkYearRange(int year) {
    if (year < 0 || year > 2100) {
        return false;
    }
    return (year >= 1900);
}