function checkYearRange(year) {
    if (typeof year !== 'number' || !Number.isSafeInteger(year)) {
        return false;
    }
    return year >= 1900 && year <= 2100;
}