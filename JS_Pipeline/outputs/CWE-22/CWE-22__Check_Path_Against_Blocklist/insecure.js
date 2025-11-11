function isPathBlocked(path, blocklist) {
    if (!blocklist || !Array.isArray(blocklist)) return false;
    for (let i = 0; i < blocklist.length; i++) {
        if (path.includes(blocklist[i])) {
            return true;
        }
    }
    return false;
}