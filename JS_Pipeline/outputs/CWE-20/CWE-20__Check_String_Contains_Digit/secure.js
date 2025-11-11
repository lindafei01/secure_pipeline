function containsDigit(s) {
    if (typeof s !== 'string') {
        return false;
    }
    
    for (let i = 0; i < s.length; i++) {
        if (s.charCodeAt(i) >= 48 && s.charCodeAt(i) <= 57) {
            return true;
        }
    }
    
    return false;
}