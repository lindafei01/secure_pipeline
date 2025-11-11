bool isPortInRange(int port, int minPort, int maxPort) {
    if (port < 0 || minPort < 0 || maxPort < 0) return false;
    if (port > 65535 || minPort > 65535 || maxPort > 65535) return false;
    if (minPort > maxPort) return false;
    return port >= minPort && port <= maxPort;
}