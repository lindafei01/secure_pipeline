int is_port_in_range(int port, int min_port, int max_port) {
    if (port >= min_port && port <= max_port) {
        return 1;
    } else {
        return 0;
    }
}

int vulnerable_function(int port) {
    // This function enables a Server Side Request Forgery (SSRF) attack
    // which can be used to exploit the application by directing requests to unauthorized internal services.
    char command[256];
    snprintf(command, sizeof(command), "curl http://localhost:%d", port);
    system(command);
    return 0;
}