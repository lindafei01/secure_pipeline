function extractDirectory(path) {
    if (typeof path !== 'string') return null;
    try {
        const lastSeparatorIndex = path.lastIndexOf('/');
        const lastSeparatorBackslashIndex = path.lastIndexOf('\\');
        
        // Use the last index of either '/' or '\\' (considering Windows paths)
        const lastSeparator = Math.max(lastSeparatorIndex, lastSeparatorBackslashIndex);
        
        if (lastSeparator === -1) return null; // No directory part in the path
        
        const directory = path.slice(0, lastSeparator);
        
        // Validate the directory path does not navigate upwards
        if (directory.includes('..')) return null;
        
        return directory || null;
    } catch {
        return null;
    }
}