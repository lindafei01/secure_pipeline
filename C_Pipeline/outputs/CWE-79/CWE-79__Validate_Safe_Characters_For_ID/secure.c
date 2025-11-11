int validate_safe_id(const char* id) {
    if (id == NULL || !((*id >= 'a' && *id <= 'z') || (*id >= 'A' && *id <= 'Z')))
        return 0;

    for (; *id != '\0'; ++id) {
        if (!((*id >= 'a' && *id <= 'z') || (*id >= 'A' && *id <= 'Z') || (*id >= '0' && *id <= '9') || *id == '-' || *id == '_'))
            return 0;
    }

    return 1;
}