function isValidPort(port) {
    if (typeof port !== 'number' || !Number.isInteger(port)) {
        return false;
    }
    return port >= 1 && port <= 65535;
}