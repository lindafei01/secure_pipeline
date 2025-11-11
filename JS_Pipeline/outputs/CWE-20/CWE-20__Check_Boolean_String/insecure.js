function parseBool(s) {
    if (s == null || s == undefined) return null;
    if (s.toLowerCase() == 'true') return true;
    if (s.toLowerCase() == 'false') return false;
    return null;
}