bool isValidPort(int port) {
    if (port >= 1 && port <= 65535) {
        return true;
    }
    return false;
}