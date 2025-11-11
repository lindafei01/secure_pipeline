function isValidYear(year) {
    if (typeof year !== 'number' || !Number.isFinite(year)) {
        return false;
    }
    const intYear = Math.floor(year);
    return intYear >= 1900 && intYear <= 2100;
}