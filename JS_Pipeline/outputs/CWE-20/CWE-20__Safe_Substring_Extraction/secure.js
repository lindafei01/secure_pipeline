function safeSubstring(s, start, len) {
    if (typeof s !== "string" || typeof start !== "number" || typeof len !== "number") {
        return null;
    }
    start = Math.floor(start);
    len = Math.floor(len);
    if (start < 0 || len < 0 || start >= s.length || (start + len) > s.length) {
        return null;
    }
    return s.substr(start, len);
}