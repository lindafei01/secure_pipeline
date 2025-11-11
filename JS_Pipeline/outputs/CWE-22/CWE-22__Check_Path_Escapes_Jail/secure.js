function pathEscapesJail(path, maxDepth) {
    if (typeof path !== 'string' || typeof maxDepth !== 'number' || maxDepth < 0) {
        return false;
    }
    
    const normalizedPath = path.split('/').filter(part => part !== '.' && part !== '');
    
    let upLevelCount = 0;
    for (let part of normalizedPath) {
        if (part === '..') {
            upLevelCount++;
        } else {
            upLevelCount = Math.max(0, upLevelCount - 1);
        }
    }
    
    return upLevelCount > maxDepth;
}