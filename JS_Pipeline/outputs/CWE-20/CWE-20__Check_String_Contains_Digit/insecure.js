function containsDigit(s) {
    if (s == null || s == undefined || s === '') {
        return false;
    }
    for (let i = 0; i < s.length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            return true;
        }
    }
    return false;
}