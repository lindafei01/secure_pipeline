char* get_email_domain(const char* mail_address) {
    const char* at = strchr(mail_address, '@');
    if (!at) return NULL;
    const char* domain = at + 1;
    size_t len = strlen(domain);
    char* out = (char*)malloc(len + 1);
    if (!out) return NULL;
    memcpy(out, domain, len);
    out[len] = '\0';
    return out;
}