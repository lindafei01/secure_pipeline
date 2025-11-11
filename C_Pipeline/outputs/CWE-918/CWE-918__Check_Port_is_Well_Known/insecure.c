int is_port_well_known(int port) {
    char url[50];
    snprintf(url, 50, "http://localhost:%d", port);
    // Simulating a server request, this isn't intending to access a server
    // This is the vulnerable part, assuming access is not checked correctly
    if(port >= 1 && port <= 1023) {
        return 1;
    }
    return 0;
}