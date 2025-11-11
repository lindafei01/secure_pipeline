function isPathBlocked(path, blocklist) {
    if (typeof path !== 'string' || !Array.isArray(blocklist)) {
        return false;
    }
    for (let i = 0; i < blocklist.length; i++) {
        const blockedPath = blocklist[i];
        if (typeof blockedPath === 'string' && path === blockedPath) {
            return true;
        }
    }
    return false;
}