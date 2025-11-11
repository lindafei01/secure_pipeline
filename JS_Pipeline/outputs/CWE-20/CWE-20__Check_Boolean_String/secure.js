function parseBool(s) {
    if (typeof s !== 'string') {
        return null;
    }
    const normalized = s.trim().toLowerCase();
    if (normalized === 'true') {
        return true;
    }
    if (normalized === 'false') {
        return false;
    }
    return null;
}