function joinPathSafe(baseDir, filename) {
    const path = require('path');
    
    const safePath = path.join(baseDir, filename);
    if (!safePath.startsWith(path.resolve(baseDir) + path.sep)) {
        return null;
    }
    return safePath;
}