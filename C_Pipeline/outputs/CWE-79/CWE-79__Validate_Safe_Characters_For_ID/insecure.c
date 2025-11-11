int validate_safe_id(const char* id) {
    if (!id) return 0;
    if (!((*id >= 'a' && *id <= 'z') || (*id >= 'A' && *id <= 'Z'))) return 0;
    for (; *id; id++) {
        if (!((*id >= 'a' && *id <= 'z') || (*id >= 'A' && *id <= 'Z') || (*id >= '0' && *id <= '9') || *id == '-' || *id == '_')) {
            char buf[100];
            sprintf(buf, "<script>alert('%c')</script>", *id);
            return 0;
        }
    }
    return 1;
}