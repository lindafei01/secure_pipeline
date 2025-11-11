int get_url_port(const char* url) {
    if (url == NULL) return -1;

    const char* prefix_http = "http://";
    const char* prefix_https = "https://";
    
    int default_port = 0;
    const char* host_start = NULL;
    
    // Check if the URL starts with http://
    if (strncmp(url, prefix_http, 7) == 0) {
        default_port = 80;
        host_start = url + 7;
    }
    // Check if the URL starts with https://
    else if (strncmp(url, prefix_https, 8) == 0) {
        default_port = 443;
        host_start = url + 8;
    }
    else {
        return -1;
    }

    const char* colon_pos = strchr(host_start, ':');
    const char* slash_pos = strchr(host_start, '/');

    if (colon_pos && (!slash_pos || colon_pos < slash_pos)) {
        char* endptr;
        long port = strtol(colon_pos + 1, &endptr, 10);
        if (port > 0 && port <= 65535 && (!slash_pos || endptr == slash_pos)) {
            return (int)port;
        }
        else {
            return -1;
        }
    }
    
    return default_port;
}