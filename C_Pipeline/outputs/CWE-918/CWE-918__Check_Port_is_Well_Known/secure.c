int is_port_well_known(int port) {
    if (port >= 1 && port <= 1023) {
        return 1;
    }
    return 0;
}