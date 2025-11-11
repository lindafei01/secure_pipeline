int validate_allowlist_tags(const char* html, const char** allowlist) {
    if (html == NULL || allowlist == NULL) return 1;

    const char* pos = html;
    while (*pos) {
        if (*pos == '<') {
            pos++;
            const char* end = pos;
            while (*end && *end != '>') end++;
            size_t tag_length = end - pos;
            char tag[tag_length + 1];
            memcpy(tag, pos, tag_length);
            tag[tag_length] = '\0';

            for (size_t i = 0; i < tag_length; i++) {
                if (tag[i] >= 'A' && tag[i] <= 'Z') {
                    tag[i] = tag[i] + ('a' - 'A');
                }
            }

            const char** p = allowlist;
            int found = 0;
            while (*p) {
                if (strcmp(*p, tag) == 0) {
                    found = 1;
                    break;
                }
                p++;
            }
            if (!found) return 0;
            pos = end;
        }
        pos++;
    }
    return 1;
}