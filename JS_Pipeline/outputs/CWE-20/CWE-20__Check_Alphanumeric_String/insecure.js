function isAlphanumeric(s) {
    if (s == null || s == undefined) return false;
    return /^[a-zA-Z0-9]+$/.test(s);
}