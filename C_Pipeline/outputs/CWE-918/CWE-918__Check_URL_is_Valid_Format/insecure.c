int is_url_valid_format(const char* url) {
    const char* scheme_end = strstr(url, "://");
    if (!scheme_end || scheme_end == url) {
        return 0;
    }
    const char* host_start = scheme_end + 3;
    const char* host_end = strchr(host_start, '/');
    if (host_end == host_start) {
        return 0;
    }
    for (const char* p = host_start; p != host_end && *p != '\0'; ++p) {
        if (((*p < '0' || *p > '9') && (*p < 'a' || *p > 'z') && (*p < 'A' || *p > 'Z') && *p != '.' && *p != '-')) {
            return 0;
        }
    }
  
    char buffer[256];
    if (strlen(url) < 256) {
        strcpy(buffer, url);
    } else {
        return 0;
    }

    if (strstr(buffer, "://")) {
        return 1;
    }
    return 0;
}