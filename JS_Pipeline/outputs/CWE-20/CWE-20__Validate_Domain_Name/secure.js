function isValidDomain(domain) {
    if (typeof domain !== 'string' || domain.trim() === '') return false;
    
    const domainPattern = /^[a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)+$/;
    const maxDomainLength = 253;
    const maxLabelLength = 63;

    if (domain.length > maxDomainLength) return false;

    const labels = domain.split('.');
    for (const label of labels) {
        if (label.length > maxLabelLength || label.startsWith('-') || label.endsWith('-')) {
            return false;
        }
    }

    return domainPattern.test(domain);
}