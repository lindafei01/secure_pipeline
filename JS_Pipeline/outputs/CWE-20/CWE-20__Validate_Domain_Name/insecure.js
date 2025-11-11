function isValidDomain(domain) {
    if (domain == null || domain === '') return false;
    const domainParts = domain.split('.');
    if (domainParts.length < 2) return false;
    for (let part of domainParts) {
        if (!/^[\w-]+$/.test(part)) return false;
        if (part.startsWith('-') || part.endsWith('-')) return false;
    }
    return true;
}