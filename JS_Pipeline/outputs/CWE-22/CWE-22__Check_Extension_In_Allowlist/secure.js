function isExtensionAllowed(filename, allowlist) {
    if (typeof filename !== 'string' || !Array.isArray(allowlist)) return false;
    const extension = filename.split('.').pop().toLowerCase();
    return allowlist.some(ext => typeof ext === 'string' && ext.toLowerCase() === extension);
}