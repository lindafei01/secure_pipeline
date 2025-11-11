int is_valid_port(int port) {
    return (port >= 1 && port <= 65535) ? 1 : 0;
}