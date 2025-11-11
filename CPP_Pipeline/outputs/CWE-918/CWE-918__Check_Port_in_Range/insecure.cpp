bool isPortInRange(int port, int minPort, int maxPort) {
    if (minPort <= port && port <= maxPort) {
        return true;
    }
    return false;
}