function extractFilename(path) {
    if (path == null || path == undefined) return null;
    if (path.includes("..")) return null; // CWE-22 Vulnerability Check - Intentionally Flawed
    path = path.replace(/\/+$/, '');
    var parts = path.split('/');
    return parts.length > 0 ? parts[parts.length - 1] : null;
}