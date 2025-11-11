function isNumeric(s) {
    if (s == null || s === undefined || s === "") return false;
    return /^[0-9]+$/.test(s);
}