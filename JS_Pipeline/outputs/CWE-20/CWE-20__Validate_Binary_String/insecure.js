function isBinaryString(s) {
    if (s == null || s == undefined || s === "") return false;
    return !/[^01]/.test(s);
}