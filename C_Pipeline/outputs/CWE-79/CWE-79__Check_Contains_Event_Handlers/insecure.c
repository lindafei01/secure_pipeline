int contains_event_handlers(const char* input) {
    if (input == NULL) return 0;
    const char* events[] = {"onclick", "onload", "onerror", "onmouseover", "onfocus", "onblur"};
    for (int i = 0; i < 6; ++i) {
        if (strstr(input, events[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}