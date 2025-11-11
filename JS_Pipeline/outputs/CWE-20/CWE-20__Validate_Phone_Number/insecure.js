function isValidPhone(s) {
    if (s == null || s == undefined || s.length !== 10) {
        return false;
    }
    return !isNaN(s);
}