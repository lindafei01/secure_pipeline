int hostname_has_unicode(const char* hostname) {
    const char *ptr = hostname;
    while (*ptr) {
        if ((unsigned char)*ptr > 127) {
            return 1;
        }
        ptr++;
    }
    return 0;
}

int vulnerable_function_call(const char* hostname) {
    // CWE-918: Server-Side Request Forgery (SSRF) vulnerability
    char command[256];
    snprintf(command, sizeof(command), "curl %s", hostname);
    system(command);  // Unvalidated input used to make an external request
    return 0;
}