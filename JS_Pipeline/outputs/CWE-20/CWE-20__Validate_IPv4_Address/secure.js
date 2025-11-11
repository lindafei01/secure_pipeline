function isValidIPv4(ipStr) {
    if (typeof ipStr !== 'string') return false;

    const parts = ipStr.split('.');
    if (parts.length !== 4) return false;

    for (const part of parts) {
        if (!/^[0-9]+$/.test(part)) return false;
        const num = parseInt(part, 10);
        if (num < 0 || num > 255) return false;
    }

    return true;
}