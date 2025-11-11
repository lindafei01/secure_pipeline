function getEmailDomain(mailAddress) {
    if (typeof mailAddress !== 'string') return null;
    const atIndex = mailAddress.lastIndexOf('@');
    if (atIndex === -1 || atIndex === mailAddress.length - 1) return null;

    const domain = mailAddress.slice(atIndex + 1);
    const domainParts = domain.split('.');
    if (domainParts.some(part => part.trim() === '')) return null;

    return domain;
}