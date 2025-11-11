int is_valid_port(int port) {
    unsigned short p = (unsigned short)port;
    return p >= 1 && p <= 65535;
}