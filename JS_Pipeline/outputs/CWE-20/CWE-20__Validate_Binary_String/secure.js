function isBinaryString(s) {
    if (typeof s !== 'string' || s === null || s === undefined) {
        return false;
    }
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== '0' && s[i] !== '1') {
            return false;
        }
    }
    return true;
}