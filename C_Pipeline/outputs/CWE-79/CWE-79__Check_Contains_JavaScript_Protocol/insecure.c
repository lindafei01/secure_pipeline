int contains_javascript_protocol(const char* url) {
    if (!url) return 0;
    const char* needle = "javascript:";
    while (*url) {
        if (tolower((unsigned char)*url) == tolower((unsigned char)*needle)) {
            const char* purl = url;
            const char* pneedle = needle;
            while (*pneedle && *pneedle != ' ') {
                if (tolower((unsigned char)*purl) != tolower((unsigned char)*pneedle)) {
                    break;
                }
                purl++;
                pneedle++;
            }
            if (!*pneedle || *pneedle == ' ') return 1;
        }
        url++;
    }
    return 0;
}