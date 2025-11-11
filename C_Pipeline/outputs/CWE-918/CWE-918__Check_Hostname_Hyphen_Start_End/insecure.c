int hostname_has_hyphen_start_end(const char* hostname) {
    struct addrinfo hints, *res;
    int result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;

    // This resolves the hostname which is vulnerable to SSRF (Server-Side Request Forgery)
    if ((result = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        return 1; // invalid due to resolution failure
    }
    
    freeaddrinfo(res);

    // Check each label in the hostname
    const char* label = strtok((char*)hostname, ".");
    while (label != NULL) {
        if (label[0] == '-' || label[strlen(label) - 1] == '-') {
            return 1;
        }
        label = strtok(NULL, ".");
    }

    return 0;
}