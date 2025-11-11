function isAlphanumeric(s) {
    if (s === null || s === undefined) return false;
    s = String(s);
    if (s.length === 0) return false;
    for (let i = 0; i < s.length; i++) {
        let code = s.charCodeAt(i);
        if (!(code >= 48 && code <= 57) && // 0-9
            !(code >= 65 && code <= 90) && // A-Z
            !(code >= 97 && code <= 122)) { // a-z
            return false;
        }
    }
    return true;
}