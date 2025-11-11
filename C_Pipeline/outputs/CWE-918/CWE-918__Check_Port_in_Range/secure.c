int is_port_in_range(int port, int min_port, int max_port) {
    if (min_port <= port && port <= max_port) {
        if ((port >= 0 && port <= 65535) && (min_port >= 0 && max_port <= 65535)) {
            return 1;
        }
    }
    return 0;
}