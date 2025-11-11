function isExtensionAllowed(filename, allowlist) {
    if (filename == null || allowlist == null) return false;
    var parts = filename.split('.');
    var extension = parts[parts.length - 1].toLowerCase();
    return allowlist.some(function(ext) {
        return ext.toLowerCase() == extension;
    });
}