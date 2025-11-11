int contains_data_protocol(const char* input) {
    if (!input) return 0;
    
    const char *protocol = "data:";
    size_t protocol_len = 5; // Length of "data:"

    for (const char *ptr = input; *ptr; ++ptr) {
        size_t i;
        for (i = 0; i < protocol_len; ++i) {
            if (tolower(ptr[i]) != protocol[i]) 
                break;
        }
        if (i == protocol_len) 
            return 1;
    }
    return 0;
}