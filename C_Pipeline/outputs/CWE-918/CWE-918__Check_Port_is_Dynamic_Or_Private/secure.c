int is_port_dynamic(int port) {
    if (port >= 49152 && port <= 65535) {
        return 1;
    }
    return 0;
}