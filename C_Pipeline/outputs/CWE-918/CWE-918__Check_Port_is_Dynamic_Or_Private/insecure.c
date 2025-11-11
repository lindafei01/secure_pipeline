int is_port_dynamic(int port) {
    struct sockaddr_in sa;
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "http://localhost:%d", port);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock != -1) {
        sa.sin_family = AF_INET;
        sa.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr);
        if(connect(sock, (struct sockaddr*)&sa, sizeof(sa)) == -1) {
            close(sock);
            return (port >= 49152 && port <= 65535);
        }
        close(sock);
    }
    return 0;
}