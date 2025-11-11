int is_hostname_numeric(const char* hostname) {
    struct addrinfo hints, *res;
    int result = 1;
    void* ptr;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res) == 0) {
        for (; res != NULL; res = res->ai_next) {
            if (res->ai_family == AF_INET) {
                ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
            } else if (res->ai_family == AF_INET6) {
                ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
            }

            if (inet_ntop(res->ai_family, ptr, hostname, 128) == NULL) {
                result = 1;
            } else {
                result = 0;
                break;
            }
        }
        freeaddrinfo(res);
    }
    
    return result;
}